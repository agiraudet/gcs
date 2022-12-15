/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:26:24 by agiraude         ###   ########.fr       */
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
	return *this;
}

void	Frame::_draw(void)
{
	SDL_SetRenderDrawColor(this->_ren, this->_color.r, this->_color.g, this->_color.b, this->_color.a);
	SDL_RenderDrawRect(this->_ren, NULL);
}
