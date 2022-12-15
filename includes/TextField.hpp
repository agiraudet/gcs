/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:11 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:46:12 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTFIELD_HPP
# define TEXTFIELD_HPP

#include "Frame.hpp"
#include "TextInput.hpp"
#include <string>

/// The TextField Widget's implentation
/**
 * A TextField is a Frame containing a Label that can be change by the user input.
 * When active (aka clicked on), it will record the keyboard user input and
 * display them.
 */

class	TextField : public Frame
{
	public:
		///Create a TextField at positon (x,y) of size(w,h)
		/**
		 * The maximun number of characters, as well as the font size will be
		 * determined at creation to be as close as possible to the given size.
		 */
		TextField(int x, int y, int w, int h);
		TextField(TextField const & src);
		~TextField(void);
		
	public:
		TextField & operator=(TextField const & rhs);

	public:
		///Define the fucntion to be called when the TextField is active and the return key is pressed.
		/**
		 * If validateFnct is not null, it will be called if the TextFiled is
		 * active when the return key is pressed. It will be passed the content
		 * of the TextField as argument, as well as (arg).
		 */
		void	onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg);

		/// Change the content of a TextField
		void	setText(std::string const& text);

	private:
		TextField(void);
	
	private:
		TextInput*	_input;
};

#endif
