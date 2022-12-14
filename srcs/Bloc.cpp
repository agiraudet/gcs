/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:46 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 14:25:31 by agiraude         ###   ########.fr       */
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
	this->color = rhs.color;
	return *this;
}

void	Bloc::_draw(void)
{
	SDL_SetRenderDrawColor(this->_ren, this->color.r, this->color.g, this->color.b, this->color.a);
	SDL_RenderFillRect(this->_ren, NULL);
}
