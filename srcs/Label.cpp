/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Label.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:44 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:19:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Label.hpp"
#include "utils.hpp"

Label::Label(void)
{
}

Label::Label(std::string const& text, int size, int x, int y, size_t maxC)
: Widget(x, y)
/* : _size(size), _text(text), _textTex(NULL), _maxC(maxC) */
{
	this->_size = size;
	this->_text = text;
	this->_textTex = NULL;
	this->_maxC = maxC;
	if (maxC < this->_text.size())
		this->_maxC = this->_text.size();
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
	this->_maxC = rhs._maxC;
	return *this;
}

void	Label::_resizeFromText(void)
{
	int		tampon = this->_maxC - this->_text.size();
	std::string	sampleText = this->_text;
	int		w;
	int		h;

	for (int i = 0; i < tampon; i++)
		sampleText += " ";
	TTF_SizeText(this->_font, sampleText.c_str(), &w, &h);
	this->_offset.w = w;
	this->_rect.w = w;
	this->_offset.h = h;
}

void	Label::_draw(void)
{
	if (!this->_tex)
		this->_createTex();
	if (!this->_textTex)
	{
		SDL_Color sdlColor = {this->color.r, this->color.g, this->color.b, this->color.a};

		SDL_Surface*	surfTxt = TTF_RenderText_Solid(this->_font, this->_text.c_str(), sdlColor);
		this->_textTex = SDL_CreateTextureFromSurface(this->_ren, surfTxt);
		SDL_FreeSurface(surfTxt);
	}
	/* SDL_Rect	dest = {this->_offset.x, this->_offset.y, 0, 0}; */
	SDL_Rect	dest = {0, 0, 0, 0};
	SDL_QueryTexture(this->_textTex, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(this->_ren, this->_textTex, NULL, &dest);
}

void	Label::setText(std::string const& text)
{
	this->_text = text;
}

void	Label::delTextTex(void)
{
	SDL_DestroyTexture(this->_textTex);
	this->_textTex = NULL;
}
