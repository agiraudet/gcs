/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:04:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 10:52:50 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Button_HPP
# define Button_HPP

# include "Widget.hpp"
# include <vector>

class	Button : public Widget
{
	public:

		Button(Rect const& rect, std::string const& label);
		Button(Button const & src);
		~Button(void);
		
		Button & operator=(Button const & rhs);

		int		action(SDL_Event const& event);
		void	draw(void);
		void	setColorAction(Uint8 r, Uint8 g, Uint8 b);
		void	setAction(void (*actFnct)(void* arg), void* arg);

	private:
		Button(void);
		void	_setWatchEvent(void);

		Uint32	_actColor;
		bool	_active;
		void*	_actArg;
		void	(*_actFnct)(void* arg);
};

#endif
