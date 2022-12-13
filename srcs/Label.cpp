/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Label.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:44 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/13 11:04:03 by agiraude         ###   ########.fr       */
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
	this->_size = size;
	this->_font = TTF_OpenFont("ttf/UbuntuMono-R.ttf", size);
	this->_resizeFromText();
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
	this->_size = rhs._size;
	return *this;
}

void	Label::_resizeFromText(void)
{
	int	w;
	int h;

	TTF_SizeText(this->_font, this->_text.c_str(), &w, &h);
	this->_offset.w = w;
	this->_rect.w = w;
	this->_offset.h = h;
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
	this->_resizeFromText();
}

void	Label::setText(std::string const& text)
{
	this->_text = text;
}
