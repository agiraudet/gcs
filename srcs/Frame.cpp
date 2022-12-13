/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/13 10:14:03 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp"

Frame::Frame(void)
{
}

Frame::Frame(int x, int y, int w, int h)
: Widget(x, y, w, h)
{
}

Frame::Frame(Frame const & src)
{
	*this = src;
}

Frame::~Frame(void)
{
}

Frame & Frame::operator=(Frame const & rhs)
{
	if (this == &rhs)
		return *this;
	this->color = rhs.color;
	return *this;
}

void	Frame::_draw(void)
{
	SDL_SetRenderTarget(this->_ren, this->_tex);
	SDL_SetRenderDrawColor(this->_ren, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderDrawRect(this->_ren, NULL);
	SDL_SetRenderTarget(this->_ren, NULL);
}
