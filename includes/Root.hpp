/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:01 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 22:30:06 by agiraude         ###   ########.fr       */
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
		
	private:
		Root(Root const & src);
	
	private:
		Root & operator=(Root const & rhs);

	public:
		void	addWidget(Widget* widget);
		void	render(void);
		void	passEvent(SDL_Event const& event);

	private:
		SDL_Window*				_win;
		SDL_Renderer*			_ren;
		std::vector<Widget*>	_widgets;
};

#endif
