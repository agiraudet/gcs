/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:19:12 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 14:10:24 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2/SDL.h"
#include "utils.hpp"
#include <iostream>

void	setRect(SDL_Rect& rect, int x, int y, int w, int h)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void	assignRect(SDL_Rect const& src, SDL_Rect& dst)
{
	dst.x = src.x;
	dst.y = src.y;
	dst.w = src.w;
	dst.h = src.h;
}

bool	collide(int x, int y, SDL_Rect const& rect)
{
	return ((x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h));
}

void	setPos(SDL_Rect* dst, SDL_Rect* self, SDL_Rect *pos, int const& flag)
{
	SDL_Rect	empty = {0,0,0,0};

	assignRect(*self, *pos);
	if (!dst)
		dst = &empty;
	pos->x += dst->x;
	pos->y += dst->y;

	if (flag & POSX_LEFT)
		pos->x -= self->x;
	if (flag & POSX_CENTER)
		pos->x = dst->x + (dst->w / 2 - self->w / 2);
	if (flag & POSX_RIGHT)
		pos->x = dst->x + dst->w - self->w;
	if (flag & POSY_TOP)
		pos->y -= self->y;
	if (flag & POSY_CENTER)
		pos->y = dst->y + (dst->h / 2 - self->h / 2);
	if (flag & POSY_BOTTOM)
		pos->y = dst->y + dst->h - self->h;
}

void	debugEvent(SDL_Event const& event, int offx, int offy)
{
	if (event.type != SDL_MOUSEBUTTONDOWN)
		return;
	std::cout << "realPos: " << event.motion.x << "," << event.motion.y;
	std::cout << " + (" << offx << "," << offy << ")" << std::endl;
}
