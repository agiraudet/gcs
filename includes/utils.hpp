/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:09:30 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 13:11:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "SDL2/SDL.h"

enum Pos
{
	POS_NONE	= 0,
	POSX_LEFT	= 1 << 0,
	POSX_CENTER	= 1 << 1,
	POSX_RIGHT	= 1 << 2,
	POSY_TOP	= 1 << 3,
	POSY_CENTER	= 1 << 4,
	POSY_BOTTOM	= 1 << 5
};

void	setRect(SDL_Rect& rect, int x, int y, int w, int h);
void	assignRect(SDL_Rect const& src, SDL_Rect& dst);
bool	collide(int x, int y, SDL_Rect const& rect);
void	setPos(SDL_Rect* dst, SDL_Rect* self, SDL_Rect *pos, int const& flag);

#endif
