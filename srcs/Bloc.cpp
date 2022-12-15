/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:21:48 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bloc.hpp"

Bloc::Bloc(void)
{
}

Bloc::Bloc(int x, int y, int w, int h)
: Widget(x, y, w, h)
{
}

Bloc::Bloc(Bloc const & src)
{
	*this = src;
}

Bloc::~Bloc(void)
{
}

Bloc & Bloc::operator=(Bloc const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void	Bloc::_draw(void)
{
	SDL_SetRenderDrawColor(this->_ren, this->_color.r, this->_color.g, this->_color.b, this->_color.a);
	SDL_RenderFillRect(this->_ren, NULL);
}
