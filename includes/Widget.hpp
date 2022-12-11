/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 14:29:47 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "SDL2/SDL.h"
# include <vector>

class	Widget
{
	public:
		Widget(void);
		Widget(int x, int y);
		Widget(int x, int y, int w, int h);
		Widget(Widget const & src);
		virtual ~Widget(void);
		
	public:
		Widget & operator=(Widget const & rhs);

	public:
		void			addWidget(Widget* widget);
		void			setRen(SDL_Renderer *ren);
		void			render();
		void			passEvent(SDL_Event const& event);
		void			alignPos(SDL_Rect* parent);
		virtual void	createTex(void);
		virtual void	act(SDL_Event const& event);
		virtual void	draw(void) = 0;
	
	public:
		int	pos;

	protected:
		SDL_Rect		_rect;
		SDL_Texture*	_tex;
		SDL_Renderer*	_ren;
		std::vector<Widget*>	_widgets;
};

#endif
