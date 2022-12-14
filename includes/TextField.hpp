/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:11 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:06:22 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTFIELD_HPP
# define TEXTFIELD_HPP

#include "Frame.hpp"
#include "TextInput.hpp"
#include <string>

class	TextField : public Frame
{
	public:
		TextField(int x, int y, int w, int h);
		TextField(TextField const & src);
		~TextField(void);
		
	public:
		TextField & operator=(TextField const & rhs);

	public:
		void	onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg);
		void	setText(std::string const& text);
	private:
		TextField(void);
	
	private:
		TextInput*	_input;
};

#endif
