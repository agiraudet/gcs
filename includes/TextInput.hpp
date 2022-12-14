/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextInput.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:35:00 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:09:36 by agiraude         ###   ########.fr       */
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
		TextInput(std::string const& text, int size, int x, int y, size_t maxC);
		TextInput(SDL_Rect const& hitbox);
		~TextInput(void);

	private:
		TextInput(void);
		TextInput & operator=(TextInput const & rhs);
		TextInput(TextInput const & src);
	
	private:
		void	_proccesTextInput(SDL_Event const& event);
		void	_setActive(bool state);
		void	_renderText(void);
	
	public:
		void	act(SDL_Event const& event, int offsetX, int offsetY);
		void	onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg);
		void	changeText(std::string const& text);
	
	private:
		bool	_active;
		SDL_Rect	_hitbox;
		void*		_validateArg;
		void		(*_validateFnct)(std::string const& text, void* arg);
};

#endif
