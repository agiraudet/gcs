/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:06 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:21:01 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

Widget::Widget(void)
: _tex(NULL), _visible(true)
{
	this->setColor(150,150,150,255);
}

Widget::Widget(int x, int y)
: Elem(x, y)
{
	this->_tex = NULL;
	this->_visible = true;
	this->setColor(150,150,150,255);
}

Widget::Widget(int x, int y, int w, int h)
: Elem(x, y, w, h)
{
	this->_tex = NULL;
	this->_visible = true;
	this->setColor(150,150,150,255);
}

Widget::Widget(Widget const & src)
{
	*this = src;
}

Widget::~Widget(void)
{
	if (this->_tex)
		SDL_DestroyTexture(this->_tex);
}

Widget & Widget::operator=(Widget const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_tex = rhs._tex;
	this->_visible = rhs._visible;
	this->setColor(rhs._color.r, rhs._color.g, rhs._color.b, rhs._color.a);
	return *this;
}

void	Widget::setVis(bool vis)
{
	this->_visible = vis;
}

bool	Widget::getVis(void) const
{
	return this->_visible;
}

void	Widget::redraw(void)
{
	SDL_Texture*	prevTarget = SDL_GetRenderTarget(this->_ren);
	if (!this->_tex)
		this->_createTex();
	SDL_SetRenderTarget(this->_ren, this->_tex);
	SDL_SetRenderDrawColor(this->_ren,0,0,0,0);
	SDL_RenderClear(this->_ren);
	this->_draw();
	SDL_SetRenderTarget(this->_ren, prevTarget);
}

void	Widget::_createTex(void)
{
	if (!this->_ren)
		return;
	if (!this->_tex)
	{
		this->_tex = SDL_CreateTexture(this->_ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, this->_offset.w, this->_offset.h);
		SDL_SetTextureBlendMode(this->_tex, SDL_BLENDMODE_BLEND);
	}

}

void	Widget::render()
{
	this->redraw();
	SDL_Texture*	prevTarget = SDL_GetRenderTarget(this->_ren);
	for (size_t i = 0; i < this->_widgets.size(); i++)
	{
		SDL_SetRenderTarget(this->_ren, this->_tex);
		this->_widgets[i]->render();
	}
	SDL_SetRenderTarget(this->_ren, prevTarget);
	if (this->_visible)
		SDL_RenderCopy(this->_ren, this->_tex, NULL, &this->_rect);
}

void	Widget::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	this->setColor(r, g, b, 255);
}

void	Widget::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->_color.r = r;
	this->_color.g = g;
	this->_color.b = b;
	this->_color.a = a;
}
