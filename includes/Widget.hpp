/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Widget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:40:57 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 10:23:29 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDGET_HPP
# define WIDGET_HPP

# include "SDL2/SDL.h"
# include "Rect.hpp"
# include "utils.hpp"
# include <string>
# include <map>

class	Widget
{
	public:
		Widget(void);
		Widget(Rect const& rect, std::string const& label);
		Widget(Widget const & src);
		virtual ~Widget(void);

	public:
		Widget & operator=(Widget const & rhs);

	public:
		virtual int		action(SDL_Event const& event) = 0;
		virtual void	draw(void) = 0;
	
	public:
		Rect const&			getRect(void) const;
		void				setRect(Rect const& rect);
		std::string const&	getLabel(void) const;
		void				setLabel(std::string const& label);
		Uint32				getColor(void) const;
		void				setColor(Uint8 r, Uint8 g, Uint8 b);
		SDL_Surface*		getSurf(void);
		SDL_Rect*			getSDLRect(void);
		watchEvent			getWatch(SDL_EventType const& eType) const;
		bool				getNeedBlit(void) const;
		void				setNeedBlit(bool need);

	protected:
		bool		_needBlit;
		Rect		_rect;
		std::string	_label;
		SDL_Surface	*_surf;
		Uint32		_color;
		SDL_Texture*	_tex;
		std::map<SDL_EventType, watchEvent>	_watch;


};
#endif
