/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:35:04 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 09:36:03 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

bool	collide(int x, int y, Widget* widget)
{
	SDL_Rect*	rect = widget->getSDLRect();
	if (x >= rect->x && x <= rect->x + rect->w)
	{
		if (y >= rect->y && y <= rect->y + rect->h)
			return true;
	}
	return false;
}
