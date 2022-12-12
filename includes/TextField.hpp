/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:00 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/12 16:48:56 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TextField_HPP
# define TextField_HPP

# include "Label.hpp"
# include "SDL2/SDL_ttf.h"
# include <string>

class	TextField : public Label
{
	public:
		TextField(std::string const& text, int size, size_t maxC, int x, int y);
		~TextField(void);

	private:
		TextField(void);
		TextField & operator=(TextField const & rhs);
		TextField(TextField const & src);
	
	private:
		void	_proccesTextInput(SDL_Event const& event);
		void	_setActive(bool state);
	
	public:
		void	act(SDL_Event const& event);
	
	private:
		bool	_active;
		size_t	_maxC;
		SDL_Rect	_hitbox;
};

#endif
