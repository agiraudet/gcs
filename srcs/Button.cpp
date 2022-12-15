/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:37:09 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Button.hpp"
#include "utils.hpp"
#include <iostream>

Button::Button(void)
{
}

Button::Button(int x, int y, int w, int h)
: Widget(x, y, w, h)
{
	this->_texOn = NULL;
	this->_texOff = NULL;
	this->_clicFnct = NULL;
	this->_clicArg = NULL;
	this->setColorOn(50,50,50);
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
	assignRect(rhs._rect, this->_rect);
	this->setColorOn(rhs._colorOn.r, rhs._colorOn.g, rhs._colorOn.b);
	this->_clicFnct = rhs._clicFnct;
	this->_clicArg = rhs._clicArg;
	this->_createTex();
	return *this;
}

void	Button::_createTex(void)
{
	if (!this->_ren)
		return;
	if (!this->_texOn)
		this->_texOn = SDL_CreateTexture(this->_ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, this->_rect.w, this->_rect.h);
	if (!this->_texOff)
		this->_texOff = SDL_CreateTexture(this->_ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, this->_rect.w, this->_rect.h);
	this->_tex = this->_texOff;
}

void	Button::_draw(void)
{
	SDL_SetRenderTarget(this->_ren, this->_texOn);
	SDL_SetRenderDrawColor(this->_ren, this->_colorOn.r, this->_colorOn.g, this->_colorOn.b, this->_colorOn.a);
	SDL_RenderFillRect(this->_ren, NULL);
	SDL_SetRenderTarget(this->_ren, this->_texOff);
	SDL_SetRenderDrawColor(this->_ren, this->_color.r, this->_color.g, this->_color.b, this->_color.a);
	SDL_RenderFillRect(this->_ren, NULL);
}

void	Button::_act(SDL_Event const& event, int offsetX, int offsetY)
{
	if (event.type == SDL_MOUSEBUTTONDOWN
		&& event.button.button == SDL_BUTTON_LEFT
		&& collide(event.motion.x - offsetX, event.motion.y - offsetY, this->_rect))
	{
		this->_tex = this->_texOn;
		if (this->_clicFnct)
			this->_clicFnct(this->_clicArg);
	}
	else if (event.type == SDL_MOUSEBUTTONUP
		&& event.button.button == SDL_BUTTON_LEFT)
	{
		this->_tex = this->_texOff;
	}
}

void	Button::onClic(void (*clicFnct)(void *arg), void* arg)
{
	this->_clicArg = arg;
	this->_clicFnct = clicFnct;
}

void	Button::setColorOn(Uint8 r, Uint8 g, Uint8 b)
{
	this->_colorOn.r = r;
	this->_colorOn.g = g;
	this->_colorOn.b = b;
	this->_colorOn.a = this->_color.a;
}
