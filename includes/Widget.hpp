/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:23:50 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 11:50:43 by agiraude         ###   ########.fr       */
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
		void			redraw(void);
		void			setVis(bool vis);
		void			setVisAll(bool vis);
		bool			getVis(void) const;

	protected:
		virtual void	_createTex(void);
		virtual void	_draw(void) = 0;
	
	protected:
		SDL_Texture*	_tex;
		bool			_visible;
};

#endif
