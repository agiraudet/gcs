/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:12:49 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 12:38:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"
#include "utils.hpp"

Root::Root(void)
: _win(NULL), _screenSurf(NULL)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(1);
	this->_win = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, 0);
	this->_screenSurf = SDL_GetWindowSurface(this->_win);
	if (!this->_win || !this->_screenSurf)
		exit(2);
}

Root::Root(Root const & src)
{
	*this = src;
}

Root::~Root(void)
{
	for (size_t i = 0; i < this->_widgets.size(); i++)
		delete this->_widgets[i];
	if (this->_win)
		SDL_DestroyWindow(this->_win);
	SDL_Quit();
}

Root & Root::operator=(Root const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_win = rhs._win;
	this->_screenSurf = rhs._screenSurf;
	return *this;
}

void	Root::addWidget(Widget*	widget)
{
	if (!widget)
		return;
	widget->draw();
	this->_widgets.push_back(widget);
}

void	Root::_blitWidget(Widget* widget)
{
	SDL_BlitSurface(widget->getSurf(), NULL, this->_screenSurf, widget->getSDLRect());
	widget->setNeedBlit(false);
}

void	Root::update(void)
{
	bool	updated = false;

	for (size_t i = 0; i < this->_widgets.size(); i++)
	{
		if (this->_widgets[i]->getNeedBlit())
		{
			this->_blitWidget(this->_widgets[i]);
			updated = true;
		}
	}
	if (updated)
		SDL_UpdateWindowSurface(this->_win);
}

void	Root::processEvent(SDL_Event const& event)
{
	for (size_t i = 0; i < this->_widgets.size(); i++)
	{
		watchEvent	flag = this->_widgets[i]->getWatch(static_cast<SDL_EventType>(event.type));
		
		if (flag & NEVER)
			continue;
		else if (flag & ALWAYS)
		{
			this->_widgets[i]->action(event);
			continue;
		}
		else if (flag & (INSIDE | OUTSIDE))
		{
			bool inside = collide(event.motion.x, event.motion.y, this->_widgets[i]);
			if ((inside && flag & INSIDE) || (!inside && flag & OUTSIDE))
				this->_widgets[i]->action(event);
		}
	}
	this->update();
}
