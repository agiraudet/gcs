/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:20:23 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/08 14:04:02 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rect.hpp"

Rect::Rect(void)
{
	this->_rect.x = 0;
	this->_rect.y = 0;
	this->_rect.w = 0;
	this->_rect.h = 0;
}

Rect::Rect(int x, int y, int w, int h)
{
	this->_rect.x = x;
	this->_rect.y = y;
	this->_rect.w = w;
	this->_rect.h = h;
}

Rect::Rect(Rect const & src)
{
	*this = src;
}

Rect::~Rect(void)
{
}

int	Rect::getX(void) const
{
	return this->_rect.x;
}

int	Rect::getY(void) const
{
	return this->_rect.y;
}

int	Rect::getW(void) const
{
	return this->_rect.w;
}

int	Rect::getH(void) const
{
	return this->_rect.h;
}

SDL_Rect*	Rect::getSDLRect(void)
{
	return &this->_rect;
}

Rect & Rect::operator=(Rect const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_rect.x = rhs._rect.x;
	this->_rect.y = rhs._rect.y;
	this->_rect.w = rhs._rect.w;
	this->_rect.h = rhs._rect.h;
	return *this;
}

