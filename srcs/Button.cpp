/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:08:33 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 12:24:47 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Button.hpp"

Button::Button(void)
{
	this->_actArg = NULL;
	this->_actFnct = NULL;
	this->_active = false;
	this->_setWatchEvent();
}

Button::Button(Rect const& rect, std::string const& label)
: Widget(rect, label)
{
	this->_actArg = NULL;
	this->_actFnct = NULL;
	this->_active = false;
	this->_setWatchEvent();
}

Button::Button(Button const & src)
{
	*this = src;
}

Button::~Button(void)
{
}

Button & Button::operator=(Button const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_rect = rhs._rect;
	this->_label = rhs._label;
	this->_actColor = rhs._actColor;
	this->_actArg = rhs._actArg;
	this->_actFnct = rhs._actFnct;
	return *this;
}

void	Button::_setWatchEvent(void)
{
	this->_watch[SDL_MOUSEBUTTONDOWN] = INSIDE;
	this->_watch[SDL_MOUSEBUTTONUP] = ALWAYS;
}

int	Button::action(SDL_Event const& event)
{
	bool	oldState = this->_active;
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		this->_active = true;
		if (this->_actFnct)
			this->_actFnct(this->_actArg);
	}
	else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
	{
		this->_active = false;
	}
	if (oldState != this->_active)
		this->draw();
	return 0;
}

void	Button::draw(void)
{
	if (this->_active)
		SDL_FillRect(this->_surf, NULL, this->_actColor);
	else
		SDL_FillRect(this->_surf, NULL, this->_color);
	this->_needBlit = true;
}

void	Button::setColorAction(Uint8 r, Uint8 g, Uint8 b)
{
	this->_actColor = SDL_MapRGB(this->_surf->format, r, g, b);
}

void	Button::setAction(void (*actFnct)(void* arg), void* arg)
{
	this->_actArg = arg;
	this->_actFnct = actFnct;
}
