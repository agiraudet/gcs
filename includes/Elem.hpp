/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 10:46:41 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_HPP
# define ELEM_HPP

# include "SDL2/SDL.h"
# include <vector>

class	Widget;

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
		virtual void	render(void) = 0;
		virtual void	act(SDL_Event const& event, int offsetX, int offsetY);
		void			addWidget(Widget* widget);
		SDL_Renderer*	getRen(void);
		void			setRen(SDL_Renderer *ren);
		void			passEvent(SDL_Event const& event, int offsetX, int offsetY);
		void			alignPos(SDL_Rect* parent);
		void			resize(int w, int h);
	
	public:
		int	pos;

	protected:
		SDL_Rect		_offset;
		SDL_Rect		_rect;
		SDL_Renderer*	_ren;
		std::vector<Widget*>	_widgets;
};

#endif
