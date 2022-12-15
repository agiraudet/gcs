/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:06 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:03:15 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"
#include "Elem.hpp"
#include "utils.hpp"

Elem::Elem(void)
: _pos(POS_NONE), _ren(NULL)
{
	setRect(this->_offset, 0, 0, 0, 0);
	assignRect(this->_offset, this->_rect);
}

Elem::Elem(int x, int y)
: _pos(POS_NONE), _ren(NULL)
{
	setRect(this->_offset, x, y, 0, 0);
	assignRect(this->_offset, this->_rect);
}

Elem::Elem(int x, int y, int w, int h)
: _pos(POS_NONE), _ren(NULL)
{
	setRect(this->_offset, x, y, w, h);
	assignRect(this->_offset, this->_rect);
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
	assignRect(rhs._offset, this->_offset);
	this->_ren = rhs._ren;
	this->_pos = rhs._pos;
	return *this;
}

void	Elem::setRen(SDL_Renderer* ren)
{
	this->_ren = ren;
	for (size_t i  = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->setRen(ren);
}

void	Elem::resize(int w, int h)
{
	this->_offset.w = w;
	this->_offset.h = h;
}

void	Elem::addWidget(Widget* widget)
{
	if (!widget)
		return;
	widget->setRen(this->_ren);
	widget->alignPos(&this->_rect);
	this->_widgets.push_back(widget);
}

void	Elem::passEvent(SDL_Event const& event, int offsetX, int offsetY)
{
	this->_act(event, offsetX, offsetY);
	offsetX += this->_rect.x;
	offsetY += this->_rect.y;
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->passEvent(event, offsetX, offsetY);
}

void	Elem::alignPos(SDL_Rect* parent)
{
	SDL_Rect	empty = {0,0,0,0};

	if (!parent)
		parent = &empty;
	assignRect(this->_offset, this->_rect);

	if (this->_pos & POSX_CENTER)
		this->_rect.x += parent->w / 2 - this->_rect.w / 2;
	else if (this->_pos & POSX_RIGHT)
		this->_rect.x += parent->w - this->_rect.w;

	if (this->_pos & POSY_CENTER)
		this->_rect.y += parent->h / 2 - this->_rect.h / 2;
	else if (this->_pos & POSY_BOTTOM)
		this->_rect.y += parent->h - this->_rect.h;

	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->alignPos(&this->_rect);
}

void	Elem::setPos(int pos)
{
	this->_pos = pos;
}

void	Elem::_act(SDL_Event const& event, int offsetX, int offsetY)
{
}
