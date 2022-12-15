/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:14:47 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:15:49 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"
#include "Widget.hpp"
#include "utils.hpp"

Root::Root(void)
: _win(NULL)
{
	this->setColor(0,0,0,0);
	setRect(this->_rect, 0, 0, 720, 480);
	this->_createWin();
}

Root::Root(int screenW, int screenH)
: _win(NULL)
{
	this->setColor(0,0,0,0);
	setRect(this->_rect, 0, 0, screenW, screenH);
	this->_createWin();
}

void	Root::_createWin(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(1);
	this->_win = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->_rect.w, this->_rect.h, 0);
	if (!this->_win)
	{
		SDL_Quit();
		exit(2);
	}
	this->_ren = SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED);
	if (!this->_ren)
	{
		SDL_DestroyWindow(this->_win);
		SDL_Quit();
		exit(3);
	}
	if (TTF_Init() < 0)
	{
		SDL_DestroyWindow(this->_win);
		SDL_DestroyRenderer(this->_ren);
		SDL_Quit();
		exit(3);
	}
}

Root::Root(Root const & src)
{
	*this = src;
}

Root::~Root(void)
{
	TTF_Quit();
	SDL_DestroyRenderer(this->_ren);
	SDL_DestroyWindow(this->_win);
	SDL_Quit();
}

Root & Root::operator=(Root const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_win = rhs._win;
	this->setColor(rhs._color.r, rhs._color.g, rhs._color.b, rhs._color.a);
	assignRect(rhs._rect, this->_rect);
	return *this;
}

void	Root::render(void)
{
	SDL_SetRenderTarget(this->_ren, NULL);
	SDL_SetRenderDrawColor(this->_ren, this->_color.r, this->_color.g, this->_color.b, this->_color.a);
	SDL_RenderClear(this->_ren);
	for (size_t i = 0; i < this->_widgets.size(); i++)
	{
		SDL_SetRenderTarget(this->_ren, NULL);
		this->_widgets[i]->render();
	}
	SDL_RenderPresent(this->_ren);
}

void	Root::_act(SDL_Event const& event, int offsetX, int offsetY)
{
	if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		this->resize(event.window.data1, event.window.data2);
		this->alignPos(NULL);
	}
}

void	Root::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->_color.r = r;
	this->_color.g = g;
	this->_color.b = b;
	this->_color.a = a;
}
