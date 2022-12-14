/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gui.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:35:45 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:47:02 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gui.hpp"
#include "Widget.hpp"

Gui::Gui(void)
{
}

Gui::Gui(SDL_Renderer* ren, int x, int y, int w, int h)
: Elem(x, y, w, h)
{
	this->_ren = ren;
	this->_guiTex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, w, h);
	//SDL_SetTextureBlendMode(this->_guiTex, SDL_BLENDMODE_BLEND);
}

Gui::Gui(Gui const & src)
{
	*this = src;
}

Gui::~Gui(void)
{
}

Gui & Gui::operator=(Gui const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_ren = rhs._ren;
	this->_guiTex = rhs._guiTex;
	return *this;
}

void	Gui::render(void)
{
	SDL_SetRenderTarget(this->_ren, this->_guiTex);
	SDL_SetRenderDrawColor(this->_ren, 0,0,0,0);
	SDL_RenderClear(this->_ren);
	for (size_t i = 0; i < this->_widgets.size(); i++)
	{
		SDL_SetRenderTarget(this->_ren, this->_guiTex);
		this->_widgets[i]->render();
	}
	SDL_SetRenderTarget(this->_ren, NULL);
	SDL_RenderCopy(this->_ren, this->_guiTex, NULL, &this->_rect);
	SDL_RenderPresent(this->_ren);
}
