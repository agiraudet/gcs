/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:05:59 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_HPP
# define ELEM_HPP

# include "SDL2/SDL.h"
# include <vector>

class	Widget;

/// The Abstract Elem class
/**
 * Every thing in this library is an Elem. It manage the size/position of an
 * element, as well as the widgets attach to it.
 */
class	Elem
{
	public:
		/// Default constructor, for an empty Elem
		/**
		 * Create an Elem at position (0,0), of size (0,0);
		 */
		Elem(void);

		/// Constructor for an Elem of unknow size
		/**
		 * Create an Elem at position (x,y) of size (0,0);
		 */
		Elem(int x, int y);

		/// Constructor for an Elem with defined position and size
		/**
		 * Create an Elem at postion (x,y) of size (w,h)
		 */
		Elem(int x, int y, int w, int h);

		/// Copy constructor of an Elem
		Elem(Elem const & src);

		/// Default destructor of an Elem
		/**
		 * TODO
		 */
		virtual ~Elem(void);
		
	public:
		Elem & operator=(Elem const & rhs);

	public:
		/// Defined by the implementations
		virtual void	render(void) = 0;

		/// Add a child widget to the Elem
		/**
		 * Take a pointer to a widget and add it to the child list of the Elem.
		 * Each event received by the function passEvent() of the elem will be
		 * passed onto it's childs.
		 * This function will set the child renderer to be the same as it's own,
		 * and called the alignPos() function of the child passing it's own
		 * SDL_Rect as argument.
		 */
		void			addWidget(Widget* widget);

		/// Set the SDL_Renderer* used by an Elem
		void			setRen(SDL_Renderer *ren);

		///Give an event to an elem to be acted upon.
		/**
		 * The Elem will call the _act() function with the event as argument.
		 * It will then proceed to pass the event onto it's childs if it has any
		 */
		void			passEvent(SDL_Event const& event, int offsetX, int offsetY);

		/**Use the position defined with setPos() to align himself and its 
		 * childrens correclty.
		 * Must be given the SDL_Rect of its parent Elem for it to know
		 * how to align himself. Will then call the same function on each of its
		 * childrens, with it's own SDL_Rect as argument. 
		 * This function is automaticly called by the addWidget() function.
		 * It should only be called manually if you know what you are doing.
		 */
		void			alignPos(SDL_Rect* parent);

		///Change the size of an Elem.
		/**
		 * WIP
		 * currently, wont touch the childs when resizing.
		 */
		void			resize(int w, int h);

		/// Define how an Elem should align with it's parent.
		/**
		 * If set to POS_NONE, the initial position of the elem is used.
		 * X position can be either POSX_LEFT, POSX_CENTER, POSX_RIGHT
		 * Y position can be either POSY_TOP, POSY_CENTER, POST_BOTTOM
		 * The x and y values defined at creation will be added, 
		 * and thus be used as margins.
		 * Positives values should be used with POSX_LEFT and POSY_TOP,
		 * negatives ones with POSX_RIGHT and POSY_BOTTOM,
		 * and either with POSX_CENTER and POSY_CENTER.
		 */
		void			setPos(int pos);

	protected:
		virtual void	_act(SDL_Event const& event, int offsetX, int offsetY);
	
	protected:
		int				_pos;
		SDL_Rect		_offset;
		SDL_Rect		_rect;
		SDL_Renderer*	_ren;
		std::vector<Widget*>	_widgets;
};

#endif
