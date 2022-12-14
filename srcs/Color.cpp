/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:51:15 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:41:59 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void)
: r(255), g(255), b(255), a(0)
{
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
: r(r), g(g), b(b), a(a)
{
}

Color::Color(Uint8 r, Uint8 g, Uint8 b)
: r(r), g(g), b(b), a(255)
{
}

Color::Color(Color const & src)
{
	*this = src;
}

Color::~Color(void)
{
}

Color & Color::operator=(Color const & rhs)
{
	if (this == &rhs)
		return *this;
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	this->a = rhs.a;
	return *this;
}

