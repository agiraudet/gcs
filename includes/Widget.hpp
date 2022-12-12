/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 13:37:17 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "Elem.hpp"

/// The Abstract Widget class
/**
 * This class is the basic building bloc for a gcsi Gui. It handle the drawing
 * of an element to the screen.
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
		/** Widget assignation operator */
		Widget & operator=(Widget const & rhs);

	public:
		/// Blit the widget Texture to the Renderer
		void			render(void);

		/// Redraw the widget to his Texture
		/**
		 * Create the widget Texture if it does not already exist, then draw the
		 * widget on it using it's current parameters.
		 */
		void			redraw(void);

		/// Change the widget visibility to vis
		void			setVis(bool vis);

		/// Change the widget and all of its childrens visibily to vis
		void			setVisAll(bool vis);

		/// Return the widget current visibility
		bool			getVis(void) const;

	protected:
		/// Create the widget Texture
		/**
		 * Use the SDL_Renderer pointed to by the _ren member of the Elem part
		 * of the widget, and crate a texture of a size defined by the _rect
		 * member of the widget.
		 * This function can be overloaded to allow for different kind of
		 * Texture cration.
		 */
		virtual void	_createTex(void);

		/// Method allowing a Widget to be drawn on to its Texture
		virtual void	_draw(void) = 0;
	
	protected:
		/// Pointer to the widget Texture
		SDL_Texture*	_tex;

		/// Defining if the Widget should be rendered on screen.
		bool			_visible;
};

#endif
