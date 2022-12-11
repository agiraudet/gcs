/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:06 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 14:35:40 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"
#include "utils.hpp"

#include <iostream>

Widget::Widget(void)
: pos(POS_NONE), _tex(NULL), _ren(NULL)
{
}

Widget::Widget(int x, int y)
: pos(POS_NONE), _tex(NULL), _ren(NULL)
{
	setRect(this->_rect, x, y, 0, 0);
}

Widget::Widget(int x, int y, int w, int h)
: pos(POS_NONE), _tex(NULL), _ren(NULL)
{
	setRect(this->_rect, x, y, w, h);
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
	assignRect(rhs._rect, this->_rect);
	this->_ren = rhs._ren;
	this->pos = rhs.pos;
	this->createTex();
	return *this;
}

void	Widget::createTex(void)
{
	if (!this->_ren)
		return;
	if (!this->_tex)
		this->_tex = SDL_CreateTexture(this->_ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, this->_rect.w, this->_rect.h);
}

void	Widget::render()
{
	SDL_RenderCopy(this->_ren, this->_tex, NULL, &this->_rect);
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->render();
}

void	Widget::setRen(SDL_Renderer* ren)
{
	this->_ren = ren;
}

void	Widget::addWidget(Widget* widget)
{
	if (!widget)
		return;
	widget->setRen(this->_ren);
	widget->alignPos(&this->_rect);
	widget->createTex();
	widget->draw();
	this->_widgets.push_back(widget);
}

void	Widget::act(SDL_Event const& event)
{
}

void	Widget::passEvent(SDL_Event const& event)
{
	this->act(event);
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->passEvent(event);
}

void	Widget::alignPos(SDL_Rect* parent)
{
	SDL_Rect	empty = {0,0,0,0};

	if (!parent)
		parent = &empty;

	if (this->pos & POSX_LEFT)
		this->_rect.x += parent->x;
	else if (this->pos & POSX_CENTER)
		this->_rect.x += parent->x + (parent->w / 2 - this->_rect.w / 2);
	else if (this->pos & POSX_RIGHT)
		this->_rect.x += parent->x + parent->w - this->_rect.w;
	else
		this->_rect.x += parent->x;

	if (this->pos & POSY_TOP)
		this->_rect.y += parent->y;
	else if (this->pos & POSY_CENTER)
		this->_rect.y += parent->y + (parent->h / 2 - this->_rect.h / 2);
	else if (this->pos & POSY_BOTTOM)
		this->_rect.y += parent->y + parent->h - this->_rect.h;
	else
		this->_rect.y += parent->y;
}
