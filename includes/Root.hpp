/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:13:35 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:44:46 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOT_HPP
# define ROOT_HPP

# include "Elem.hpp"
# include "SDL2/SDL_ttf.h"

/// The Root Elem's Implementation
/**
 * A Root is an Elem managing the SDL_Window and SDL_Renderer for you. It should
 * only be instancied once. By just constructing it with a size, it will create
 * a resizable window and its render for you, then manage the rendering of
 * every widgets you attach to it.
 * Its easy to use if you dont want to manually use the SDL.
 * If you do however, you should consider using a Gui instead.
 */
class	Root : public Elem
{
	public:
		///Create a Root of size (720,480)
		Root(void);

		///Create a Root of size (screenW, screenH)
		Root(int screenW, int screenH);
		~Root(void);
	
	public:
		///Render every Widgets attached to the Root (directly or not) to the screen
		/**
		 * The Root will first clear the screen, using the color set by setColor()
		 * as a background.
		 */
		void	render(void);

		///Change the background color of a Root.
		void	setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	private:
		Root(Root const & src);
		Root & operator=(Root const & rhs);

	private:
		void	_createWin(void);
		void	_act(SDL_Event const& event, int offsetX, int offsetY);
	
	private:
		SDL_Window*	_win;
		SDL_Color	_color;
};

#endif
