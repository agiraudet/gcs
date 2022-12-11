/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 15:11:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "Elem.hpp"

class	Widget : public Elem
{
	public:
		Widget(void);
		Widget(int x, int y);
		Widget(int x, int y, int w, int h);
		Widget(Widget const & src);
		virtual ~Widget(void);
		
	public:
		Widget & operator=(Widget const & rhs);

	public:
		void			render(void);
		void			passEvent(SDL_Event const& event);
		virtual void	createTex(void);
		virtual void	draw(void) = 0;
	
	protected:
		SDL_Texture*			_tex;
};

#endif
