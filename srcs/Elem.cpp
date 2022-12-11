/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:06 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 15:15:38 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Elem.hpp"
#include "Widget.hpp"
#include "utils.hpp"

#include <iostream>

Elem::Elem(void)
: pos(POS_NONE), _ren(NULL)
{
	setRect(this->_rect, 0, 0, 0, 0);
}

Elem::Elem(int x, int y)
: pos(POS_NONE), _ren(NULL)
{
	setRect(this->_rect, x, y, 0, 0);
}

Elem::Elem(int x, int y, int w, int h)
: pos(POS_NONE), _ren(NULL)
{
	setRect(this->_rect, x, y, w, h);
}

Elem::Elem(Elem const & src)
{
	*this = src;
}

Elem::~Elem(void)
{
}

Elem & Elem::operator=(Elem const & rhs)
{
	if (this == &rhs)
		return *this;
	assignRect(rhs._rect, this->_rect);
	this->_ren = rhs._ren;
	this->pos = rhs.pos;
	return *this;
}

void	Elem::setRen(SDL_Renderer* ren)
{
	this->_ren = ren;
}

void	Elem::addWidget(Widget* widget)
{
	if (!widget)
		return;
	widget->setRen(this->_ren);
	widget->alignPos(&this->_rect);
	widget->createTex();
	widget->draw();
	this->_widgets.push_back(widget);
}

void	Elem::passEvent(SDL_Event const& event)
{
	this->act(event);
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->passEvent(event);
}

void	Elem::alignPos(SDL_Rect* parent)
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

void	Elem::act(SDL_Event const& event)
{
}
