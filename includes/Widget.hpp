/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:54:06 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "Elem.hpp"

/// The Abstract Widget class
/**
 * This class is the basic building bloc for a gcsi Gui. It handle the drawing
 * of an element to the screen.
 * Add interfaces to the Elem class.
 */
class	Widget : public Elem
{
	public:

		/// Default constuctor, for an empty Widget
		/**
		 * Create a widget at position (0,0), of size (0,0);
		 */
		Widget(void);

		/// Constructor for a widget of unknow size
		/**
		 * Create a widget at position (x,y), of size(0,0);
		 */
		Widget(int x, int y);

		/// Constructor for a widget with defined position and size
		/**
		 * Create a widget at postion (x,y) of size (w,h);
		 */
		Widget(int x, int y, int w, int h);
		
		/// Copy constructor for a widget
		Widget(Widget const & src);

		/// Default destructor for a widget
		/**
		 * TODO
		 */
		virtual ~Widget(void);
		
	public:
		Widget & operator=(Widget const & rhs);

	public:
		/// Blit the the texture of every childs to the texture of the Widget
		void			render(void);

		/// Redraw the widget to his Texture
		void			redraw(void);

		/// Change the widget visibility to vis
		void			setVis(bool vis);

		/// Return the widget current visibility
		bool			getVis(void) const;

		/// Change the widget color using RGB value (0-255)
		void			setColor(Uint8 r, Uint8 g, Uint8 b);

		/// Change the widget color using RGB + Alpha value (0-255)
		void			setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	protected:
		virtual void	_createTex(void);
		virtual void	_draw(void) = 0;
	
	protected:
		SDL_Texture*	_tex;
		bool			_visible;
		SDL_Color		_color;
};

#endif
