/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextInput.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:00 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/13 11:19:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTINPUT_HPP
# define TEXTINPUT_HPP

# include "Label.hpp"
# include "SDL2/SDL_ttf.h"
# include <string>

class	TextInput : public Label
{
	public:
		TextInput(std::string const& text, int size, size_t maxC, int x, int y);
		TextInput(SDL_Rect const& hitbox);
		~TextInput(void);

	private:
		TextInput(void);
		TextInput & operator=(TextInput const & rhs);
		TextInput(TextInput const & src);
	
	private:
		void	_proccesTextInput(SDL_Event const& event);
		void	_setActive(bool state);
	
	public:
		void	act(SDL_Event const& event);
		void	onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg);
	
	private:
		bool	_active;
		size_t	_maxC;
		SDL_Rect	_hitbox;
		void*		_validateArg;
		void		(*_validateFnct)(std::string const& text, void* arg);
};

#endif
