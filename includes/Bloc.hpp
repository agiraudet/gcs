/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 17:51:29 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOC_HPP
# define BLOC_HPP

# include "Widget.hpp"
# include "Color.hpp"

class	Bloc : public Widget
{
	public:
		Bloc(int x, int y, int w, int h);
		Bloc(Bloc const & src);
		~Bloc(void);
		
	public:
		Bloc & operator=(Bloc const & rhs);
	
	public:
		void	draw(void);

	private:
		Bloc(void);
	
	public:
		Color	color;
};

#endif
