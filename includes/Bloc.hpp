/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:46:49 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOC_HPP
# define BLOC_HPP

# include "Widget.hpp"

/// The Bloc Widget's implentation
/**
 * A Bloc is a rectangle of one solid color. It can be made invisible using the
 * alpha channel of its color, and is mainly usefull to hold others widgets.
 */
class	Bloc : public Widget
{
	public:
		/// Create a Bloc at position (x,y) of size(w,h)
		Bloc(int x, int y, int w, int h);
		Bloc(Bloc const & src);
		~Bloc(void);
		
	public:
		Bloc & operator=(Bloc const & rhs);
	
	private:
		void	_draw(void);

	private:
		Bloc(void);
};

#endif
