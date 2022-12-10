/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:18:17 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/08 14:00:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_HPP
# define RECT_HPP

# include "SDL2/SDL.h"

class	Rect
{
	public:

		Rect(void);
		Rect(int x, int y, int w, int h);
		Rect(Rect const & src);
		~Rect(void);
		
		Rect & operator=(Rect const & rhs);

		int			getX(void) const;
		int			getY(void) const;
		int			getW(void) const;
		int			getH(void) const;
		SDL_Rect*	getSDLRect(void);
	
	private:
		SDL_Rect	_rect;
};

#endif
