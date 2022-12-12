
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextField.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:44 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 14:51:26 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TextField.hpp"
#include "utils.hpp"

TextField::TextField(void)
: Label("", 12, 0, 0)
{
	this->_active = false;
	this->_maxC = 80;
	setRect(this->_hitbox, 0, 0, static_cast<int>(this->_maxC * this->_size), this->_size);
}

TextField::TextField(std::string const& text, int size, size_t maxC, int x, int y)
: Label(text, size, x, y)
{
	this->_active = false;
	this->_maxC = maxC;
	setRect(this->_hitbox, 0, 0, static_cast<int>(this->_maxC * this->_size), this->_size);
}

TextField::TextField(TextField const & src)
: Label("",12,  0, 0)
{
	*this = src;
}

TextField::~TextField(void)
{
}

TextField & TextField::operator=(TextField const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_active = rhs._active;
	this->_maxC = rhs._maxC;
	assignRect(rhs._hitbox, this->_hitbox);
	return *this;
}

void	TextField::act(SDL_Event const& event)
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

void	TextField::_proccesTextInput(SDL_Event const& event)
{
	bool	renderText = false;

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_BACKSPACE && this->_text.size() > 0)
		{
			this->_text.pop_back();
			renderText = true;
		}
		else if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_RETURN)
		{
			this->_setActive(false);
		}
	}
	else if (event.type == SDL_TEXTINPUT && this->_text.size() <= this->_maxC)
	{
		this->_text += event.text.text;
		renderText = true;
	}

	if (renderText)
	{
		if (this->_text.size() <= 0)
			this->_text = " ";
		this->_createTex();
	}
}

void	TextField::_setActive(bool state)
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
