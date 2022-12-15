/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Label.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:00 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:41:04 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_HPP
# define LABEL_HPP

# include "Widget.hpp"
# include "SDL2/SDL_ttf.h"
# include <string>

/// The Label Widget's implentation
/**
 * A Label is a string of characters rendered to the screen. You can change it's
 * content and color in realtime.
 */

class	Label : public Widget
{
	public:
		///	Create a Label displaying the text (text) of fontsize (size)
		/**
		 * The Label will be create at position (x,y).
		 * The text it displays can be change anytime, but should not excede
		 * the size of (maxC). If maxC is 0, the size (text) will be used instead.
		 */
		Label(std::string const& text, int size, int x, int y, size_t maxC);
		~Label(void);

	private:
		Label(void);
		Label & operator=(Label const & rhs);
		Label(Label const & src);
		Label(TTF_Font* font, std::string const& text, int x, int y, size_t maxC);

	protected:
		void	_draw(void);
		void	_resizeFromText(void);
		void	_delTextTex(void);

	public:
		///Change the text displayed by a Label.
		void	setText(std::string const& text);

	protected:
		int			_size;
		std::string	_text;
		TTF_Font*	_font;
		SDL_Texture*	_textTex;
		size_t			_maxC;
};

#endif
