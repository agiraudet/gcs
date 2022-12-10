/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:08:33 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 13:12:25 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp"
#include "utils.hpp"

Frame::Frame(void)
{
	this->_setWatchEvent();
}

Frame::Frame(Rect const& rect, std::string const& label)
: Widget(rect, label)
{
	this->_setWatchEvent();
}

Frame::Frame(Frame const & src)
{
	*this = src;
}

Frame::~Frame(void)
{
	for (size_t i = 0; i < this->_childs.size(); i++)
		delete this->_childs[i];
}

Frame & Frame::operator=(Frame const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_rect = rhs._rect;
	this->_label = rhs._label;
	return *this;
}

void	Frame::_setWatchEvent(void)
{
	this->_watch[SDL_KEYDOWN] = ALWAYS;
	this->_watch[SDL_MOUSEMOTION] = INSIDE;
	this->_watch[SDL_MOUSEBUTTONDOWN] = INSIDE;
	this->_watch[SDL_MOUSEBUTTONUP] = ALWAYS;
}

void	Frame::addChild(Widget* child)
{
	if (!child)
		return;
	child->draw();
	this->_childs.push_back(child);
}

int	Frame::action(SDL_Event const& event)
{
	for (size_t i = 0; i < this->_childs.size(); i++)
	{
		watchEvent	flag = this->_childs[i]->getWatch(static_cast<SDL_EventType>(event.type));
		
		if (flag & NEVER)
			continue;
		else if (flag & ALWAYS)
		{
			this->_childs[i]->action(event);
			continue;
		}
		else if (flag & (INSIDE | OUTSIDE))
		{
			bool inside = collide(event.motion.x - this->_rect.getX(),
					event.motion.y - this->_rect.getY(), this->_childs[i]);
			if ((inside && flag & INSIDE) || (!inside && flag & OUTSIDE))
				this->_childs[i]->action(event);
		}
	}
	this->update();
	return 0;
}

void	Frame::update(void)
{
	for (size_t i = 0; i < this->_childs.size(); i++)
	{
		if (this->_childs[i]->getNeedBlit())
		{
			SDL_BlitSurface(this->_childs[i]->getSurf(), NULL, this->_surf,
							this->_childs[i]->getSDLRect());
			this->_childs[i]->setNeedBlit(false);
			this->_needBlit = true;
		}
	}
}

void	Frame::draw(void)
{

	SDL_FillRect(this->_surf, NULL, this->_color);
	for (size_t i = 0; i < this->_childs.size(); i++)
	{
		SDL_BlitSurface(this->_childs[i]->getSurf(), NULL, this->_surf,
						this->_childs[i]->getSDLRect());
		this->_childs[i]->setNeedBlit(false);
	}
	this->_needBlit = true;
}
