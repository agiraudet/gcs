
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
: Label("", 12, 0, 0, 80)
{
	this->_active = false;
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	setRect(this->_hitbox, 0, 0,
			static_cast<int>(this->_maxC * (this->_size/2)), this->_size);
}

TextInput::TextInput(std::string const& text, int size, int x, int y, size_t maxC)
: Label(text, size, x, y, maxC)
{
	this->_active = false;
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	setRect(this->_hitbox, 0, 0,
			static_cast<int>(this->_maxC * (this->_size/2)), this->_size);
}

TextInput::TextInput(SDL_Rect const& hitbox)
: Label("", hitbox.h - 4, hitbox.x, hitbox.y, hitbox.w / ((hitbox.h-2)/2))
{
	this->_active = false;
	this->_validateFnct = NULL;
	this->_validateArg = NULL;
	assignRect(hitbox, this->_hitbox);
}

TextInput::TextInput(TextInput const & src)
: Label("",12,  0, 0, 80)
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

void	TextInput::act(SDL_Event const& event, int offsetX, int offsetY)
{
	if ((event.type == SDL_KEYDOWN || event.type == SDL_TEXTINPUT) && this->_active)
		this->_proccesTextInput(event);
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		this->_hitbox.x = this->_rect.x;
		this->_hitbox.y = this->_rect.y;
		if (collide(event.motion.x - offsetX, event.motion.y - offsetY, this->_hitbox))
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
			this->_renderText();
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
	else if (event.type == SDL_TEXTINPUT && this->_text.size() < this->_maxC -1)
	{
		this->_text += event.text.text;
		this->_renderText();
	}
}

void	TextInput::_renderText(void)
{
	bool	empty = false;

	if (this->_active)
		this->_text += "_";
	if (this->_text.size() == 0)
	{
		empty = true;
		this->_text += " ";
	}

	if (this->_textTex)
		SDL_DestroyTexture(this->_textTex);
	SDL_Color sdlColor = {this->color.r, this->color.g, this->color.b, this->color.a};
	SDL_Surface*	surfTxt = TTF_RenderText_Solid(this->_font, this->_text.c_str(), sdlColor);
	this->_textTex = SDL_CreateTextureFromSurface(this->_ren, surfTxt);
	SDL_FreeSurface(surfTxt);

	if (empty)
		this->_text.pop_back();
	if (this->_active)
		this->_text.pop_back();
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
	this->_renderText();
}

void	TextInput::changeText(std::string const& text)
{
	this->_text = text;
	this->_renderText();
}
