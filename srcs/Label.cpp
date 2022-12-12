/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Label.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:44 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 10:51:41 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Label.hpp"
#include "utils.hpp"

Label::Label(void)
{
}

Label::Label(std::string const& text, int size, int x, int y)
{
	this->_text = text;
	this->_font = TTF_OpenFont("futuram.ttf", size);

	int	w;
	int	h;

	TTF_SizeText(this->_font, text.c_str(), &w, &h);
	setRect(this->_offset, x, y, w, h);
}

Label::Label(Label const & src)
{
	*this = src;
}

Label::~Label(void)
{
}

Label & Label::operator=(Label const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_text = rhs._text;
	this->color = rhs.color;
	this->_font = rhs._font;
	return *this;
}

void	Label::_draw(void)
{
}

void	Label::_createTex(void)
{
	SDL_Color sdlColor = {this->color.r, this->color.g, this->color.b, this->color.a};

	SDL_Surface*	surfTxt = TTF_RenderText_Solid(this->_font, this->_text.c_str(), sdlColor);
	if (this->_tex)
		SDL_DestroyTexture(this->_tex);
	this->_tex = SDL_CreateTextureFromSurface(this->_ren, surfTxt);
	SDL_FreeSurface(surfTxt);
}
