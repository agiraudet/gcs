/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:04:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 13:12:14 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_HPP
# define FRAME_HPP

# include "Widget.hpp"
# include <vector>

class	Frame : public Widget
{
	public:

		Frame(Rect const& rect, std::string const& label);
		Frame(Frame const & src);
		~Frame(void);
		
		Frame & operator=(Frame const & rhs);

		int		action(SDL_Event const& event);
		void	draw(void);
		void	setVis(bool vis);
		void	addChild(Widget* child);
		void	update(void);

	private:
		Frame(void);
		void	_setWatchEvent(void);
		bool					_visible;
		std::vector<Widget*>	_childs;
};

#endif
