/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/13 10:54:49 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_HPP
# define FRAME_HPP

# include "Widget.hpp"
# include "Color.hpp"

class	Frame : public Widget
{
	public:
		Frame(int x, int y, int w, int h);
		Frame(Frame const & src);
		~Frame(void);
		
	public:
		Frame & operator=(Frame const & rhs);
	
	private:
		void	_draw(void);

	protected:
		Frame(void);
	
	public:
		Color	color;
};

#endif
