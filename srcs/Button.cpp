/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 15:37:16 by agiraude         ###   ########.fr       */
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
	this->colorOn = Color(50,50,50);
	this->colorOff = Color(75,75,75);
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
	this->colorOn = rhs.colorOn;
	this->colorOff = rhs.colorOff;
	this->_clicFnct = rhs._clicFnct;
	this->_clicArg = rhs._clicArg;
	this->createTex();
	return *this;
}

void	Button::createTex(void)
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

void	Button::draw(void)
{
	SDL_SetRenderTarget(this->_ren, this->_texOn);
	SDL_SetRenderDrawColor(this->_ren, this->colorOn.r, this->colorOn.g, this->colorOn.b, this->colorOn.a);
	SDL_RenderFillRect(this->_ren, NULL);
	SDL_SetRenderTarget(this->_ren, this->_texOff);
	SDL_SetRenderDrawColor(this->_ren, this->colorOff.r, this->colorOff.g, this->colorOff.b, this->colorOff.a);
	SDL_RenderFillRect(this->_ren, NULL);
	SDL_SetRenderTarget(this->_ren, NULL);
}

void	Button::act(SDL_Event const& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN
		&& event.button.button == SDL_BUTTON_LEFT
		&& collide(event.motion.x, event.motion.y, this->_rect))
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
