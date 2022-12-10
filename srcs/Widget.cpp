/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:05:30 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 10:24:01 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

Widget::Widget(void)
: _needBlit(true), _label("none"), _tex(NULL)
{
	this->setColor(255, 255, 255);
}

Widget::Widget(Rect const& rect, std::string const& label)
: _needBlit(true), _rect(rect), _label(label), _tex(NULL)
{
	this->_surf = SDL_CreateRGBSurface(0, rect.getW(), rect.getH(), 32, 0,0,0,0);
	this->setColor(255, 255, 255);
}

Widget::Widget(Widget const & src)
{
	*this = src;
}

Widget::~Widget(void)
{
	SDL_FreeSurface(this->_surf);
}

Widget & Widget::operator=(Widget const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_needBlit = rhs._needBlit;
	this->_rect = rhs._rect;
	this->_label = rhs._label;
	this->_color = rhs._color;
	this->_surf = rhs._surf;
	this->_watch = rhs._watch;
	return *this;
}

Rect const&	Widget::getRect(void) const
{
	return this->_rect;
}

SDL_Rect*	Widget::getSDLRect(void)
{
	return this->_rect.getSDLRect();
}

void	Widget::setRect(Rect const& rect)
{
	this->_rect = rect;
}

std::string const&	Widget::getLabel(void) const
{
	return this->_label;
}

void	Widget::setLabel(std::string const& label)
{
	this->_label = label;
}

Uint32	Widget::getColor(void) const
{
	return this->_color;
}

void	Widget::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	this->_color = SDL_MapRGB(this->_surf->format, r, g, b);
}

SDL_Surface*	Widget::getSurf(void)
{
	return this->_surf;
}

watchEvent 	Widget::getWatch(SDL_EventType const& eType) const
{
	std::map<SDL_EventType, watchEvent>::const_iterator	it;

	it = this->_watch.find(eType);
	if (it == this->_watch.end())
		return NEVER;
	return it->second;
}

bool	Widget::getNeedBlit(void) const
{
	return this->_needBlit;
}

void	Widget::setNeedBlit(bool need)
{
	this->_needBlit = need;
}
