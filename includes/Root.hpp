/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:11:03 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 12:26:50 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOT_HPP
# define ROOT_HPP

# include "SDL2/SDL.h"
# include "Widget.hpp"
# include <vector>

class	Root
{
	public:
		Root(void);
		~Root(void);
	
	public:
		void	addWidget(Widget* widget);
		void	update(void);
		void	processEvent(SDL_Event const& event);

	private:
		Root(Root const & src);
		Root & operator=(Root const & rhs);

	private:
		void	_blitWidget(Widget* widget);
	
	private:
		SDL_Window*				_win;
		SDL_Surface*			_screenSurf;
		std::vector<Widget*>	_widgets;
};

bool	collide(int x, int y, Widget* widget);

#endif
