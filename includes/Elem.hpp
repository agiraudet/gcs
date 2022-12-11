/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 14:41:22 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "SDL2/SDL.h"
# include <vector>

class	Elem
{
	public:
		Elem(void);
		Elem(int x, int y);
		Elem(int x, int y, int w, int h);
		Elem(Elem const & src);
		virtual ~Elem(void);
		
	public:
		Elem & operator=(Elem const & rhs);

	public:
		void			addWidget(Widget* widget);
		void			setRen(SDL_Renderer *ren);
		void			passEvent(SDL_Event const& event);
		void			alignPos(SDL_Rect* parent);
	
	public:
		int	pos;

	protected:
		SDL_Rect		_rect;
		SDL_Renderer*	_ren;
		std::vector<Elem*>	_widgets;
};

#endif
