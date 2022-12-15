/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gui.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:28:56 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:43:51 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_HPP
# define GUI_HPP

# include "Elem.hpp"

/// The Gui Elem's implementation
/**
 * A Gui is an Elem that should only be instancied once. It is responsable
 * for holding and redenrering every others widget.
 * This Elem implementation is usefull if you need your GUI to only occupy a
 * part of the screen, as an overlay for exemple.
 * It use an already existing SDL_Renderer, and a predefined size, as well as
 * a transparent background to be render on top of everything else.
 * If you dont need to manually render anything else, you should consider using
 * a Root instead.
 */
class	Gui : public Elem
{
	public:
		//Create a Gui at position (x,y) of size (w,h)
		/**
		 * It will use the SDL_Renderer pointed to by ren, which should
		 * not be NULL.
		 */
		Gui(SDL_Renderer* ren, int x, int y, int w, int h);
		Gui(Gui const & src);
		~Gui(void);

	public:
		///Blit the Gui to the screen.
		/**
		 * It will first render every widget attach directly or not to the Gui.
		 * The rendering will be done using the SDL_Renderer defined at creation.
		 */
		void	render(void);
		
	private:
		Gui(void);
		Gui & operator=(Gui const & rhs);

	private:
		SDL_Texture	*_guiTex;
};

#endif
