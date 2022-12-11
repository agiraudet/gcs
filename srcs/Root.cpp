/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:51:53 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 14:32:11 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"
#include "SDL2/SDL_ttf.h"

Root::Root(void)
: _win(NULL), _ren(NULL)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(1);
	this->_win = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, 0);
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
	this->_ren = rhs._ren;
	this->_widgets = rhs._widgets;
	return *this;
}

void	Root::addWidget(Widget* widget)
{
	if (!widget)
		return;
	widget->setRen(this->_ren);
	widget->alignPos(NULL);
	widget->createTex();
	widget->draw();
	this->_widgets.push_back(widget);
}

void	Root::render(void)
{
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->render();
	SDL_RenderPresent(this->_ren);
}

void	Root::passEvent(SDL_Event const& event)
{
	for (size_t i = 0; i < this->_widgets.size(); i++)
		this->_widgets[i]->passEvent(event);
}
