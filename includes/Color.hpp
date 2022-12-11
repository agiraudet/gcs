/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:49:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 14:28:44 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# include "SDL2/SDL.h"

class	Color
{
	public:
		Color(void);
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		Color(Uint8 r, Uint8 g, Uint8 b);
		Color(Color const & src);
		~Color(void);
		
	public:
		Color & operator=(Color const & rhs);

	public:
		Uint8	r;
		Uint8	g;
		Uint8	b;
		Uint8	a;
};

#endif
