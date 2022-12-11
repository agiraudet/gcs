/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:06 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 15:11:44 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

Widget::Widget(void)
: _tex(NULL)
{
}

Widget::Widget(int x, int y)
: Elem(x, y)
{
	this->_tex = NULL;
}

Widget::Widget(int x, int y, int w, int h)
: Elem(x, y, w, h)
{
	this->_tex = NULL;
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
