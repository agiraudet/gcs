/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Label.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:00 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/10 18:41:14 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_HPP
# define LABEL_HPP

# include "Widget.hpp"
# include "Color.hpp"
# include "SDL2/SDL_ttf.h"
# include <string>

class	Label : public Widget
{
	public:
		Label(TTF_Font* font, std::string const& text, int x, int y);
		Label(std::string const& text, int size, int x, int y);
		~Label(void);

	private:
		Label(void);
		Label & operator=(Label const & rhs);
		Label(Label const & src);

	public:
		void	draw(void);


	public:
		Color		color;

	private:
		std::string	_text;
		TTF_Font*	_font;
};

#endif
