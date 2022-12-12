/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:13:35 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 11:04:58 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOT_HPP
# define ROOT_HPP

# include "Elem.hpp"
# include "SDL2/SDL_ttf.h"
# include "Color.hpp"

class	Root : public Elem
{
	public:
		Root(void);
		Root(int x, int y);
		~Root(void);
	
	public:
		void	render(void);
		void	act(SDL_Event const& event);
	
	public:
		Color	color;

	private:
		Root(Root const & src);
		Root & operator=(Root const & rhs);

	private:
		void	_createWin(void);
	
	private:
		SDL_Window*	_win;
};

#endif
