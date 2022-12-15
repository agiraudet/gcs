/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:37:00 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_HPP
# define FRAME_HPP

# include "Widget.hpp"

/// The Frame Widget's implementation
/**
 * A Frame is similar to a Bloc, only using a thin colored border instead of
 * a plain solid rectangle.
 */

class	Frame : public Widget
{
	public:
		/// Create a Frame at position (x,y) of size(w,h)
		Frame(int x, int y, int w, int h);
		Frame(Frame const & src);
		~Frame(void);
		
	public:
		Frame & operator=(Frame const & rhs);
	
	private:
		void	_draw(void);

	protected:
		Frame(void);
};

#endif
