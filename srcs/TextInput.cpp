
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextInput.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:44 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 14:51:26 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TextInput.hpp"
#include "utils.hpp"

TextInput::TextInput(void)
: Label("", 12, 0, 0)
{
	this->_active = false;
	this->_maxC = 80;
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	setRect(this->_hitbox, 0, 0,
			static_cast<int>(this->_maxC * (this->_size/2)), this->_size);
}

TextInput::TextInput(std::string const& text, int size, size_t maxC, int x, int y)
: Label(text, size, x, y)
{
	this->_active = false;
	this->_maxC = maxC;
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	setRect(this->_hitbox, 0, 0,
			static_cast<int>(this->_maxC * (this->_size/2)), this->_size);
}

TextInput::TextInput(SDL_Rect const& hitbox)
: Label("", hitbox.h - 4, hitbox.x, hitbox.y)
{
	this->_active = false;
	this->_maxC = hitbox.w / ((hitbox.h - 2) / 2);
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	assignRect(hitbox, this->_hitbox);
}

TextInput::TextInput(TextInput const & src)
: Label("",12,  0, 0)
{
	*this = src;
}

TextInput::~TextInput(void)
{
}

TextInput & TextInput::operator=(TextInput const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_active = rhs._active;
	this->_maxC = rhs._maxC;
	this->_validateFnct = rhs._validateFnct;
	this->_validateArg = rhs._validateArg;
	assignRect(rhs._hitbox, this->_hitbox);
	return *this;
}

void	TextInput::act(SDL_Event const& event)
{
	if ((event.type == SDL_KEYDOWN || event.type == SDL_TEXTINPUT) && this->_active)
		this->_proccesTextInput(event);
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		this->_hitbox.x = this->_rect.x;
		this->_hitbox.y = this->_rect.y;
		if (collide(event.motion.x, event.motion.y, this->_hitbox))
			this->_setActive(true);
		else
			this->_setActive(false);
	}
}

void	TextInput::_proccesTextInput(SDL_Event const& event)
{
	bool	renderText = false;

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_BACKSPACE && this->_text.size() > 0)
		{
			this->_text.pop_back();
			renderText = true;
		}
		else if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			this->_setActive(false);
		}
		else if (event.key.keysym.sym == SDLK_RETURN)
		{
			this->_setActive(false);
			if (this->_validateFnct)
				this->_validateFnct(this->_text, this->_validateArg);
		}
	}
	else if (event.type == SDL_TEXTINPUT && this->_text.size() <= this->_maxC)
	{
		this->_text += event.text.text;
		renderText = true;
	}

	if (renderText)
	{
		bool	minText = false;
		if (this->_text.size() <= 0)
		{
			this->_text = " ";
			minText = true;
		}
		this->_createTex();
		if (minText)
			this->_text = "";
	}
}

void	TextInput::onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg)
{
	this->_validateFnct = validateFnct;
	this->_validateArg = arg;
}

void	TextInput::_setActive(bool state)
{
	if (state != this->_active)
	{
		if (state)
			SDL_StartTextInput();
		else
			SDL_StopTextInput();
	}
	this->_active = state;
}
