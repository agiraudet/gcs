/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:46:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Button_HPP
# define Button_HPP

# include "Widget.hpp"

/// The Bloc Widget's implentation
/**
 * A Button is a colored rectangle which can changed color and call a predefined
 * function when clicked on.
 * Adding a Label as a child Widget to a Button is an esay way to make an
 * interactive GUI.
 */
class	Button : public Widget
{
	public:
		/// Create a Button at position (x,y) of size(w,h)
		Button(int x, int y, int w, int h);
		Button(Button const & src);
		~Button(void);
		
	public:
		Button & operator=(Button const & rhs);

	public:
		/// Defined the function to be called when the button is used
		/**
		 * clicFnct should be a pointer to a function that will be called
		 * if sets when the Button is clicked on.
		 * If sets, arg will be passed to this fucntion as argument.
		 */
		void	onClic(void (*clicFnct)(void *arg), void* arg);

		/// Define the Button color when clicked on.
		void	setColorOn(Uint8 r, Uint8 g, Uint8 b);

	private:
		Button(void);
	
	private:
		void	_act(SDL_Event const& event, int offsetX, int offsetY);
		void	_draw(void);
		void	_createTex(void);
	
	private:
		SDL_Texture*	_texOn;
		SDL_Texture*	_texOff;
		void*			_clicArg;
		void			(*_clicFnct)(void* arg);
		SDL_Color		_colorOn;
};

#endif
