/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextField.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:42:53 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 13:41:35 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TextField.hpp"
#include "TextInput.hpp"
#include "utils.hpp"

TextField::TextField(void)
{
}

TextField::TextField(int x, int y, int w, int h)
: Frame(x, y, w, h)
{
	SDL_Rect	hitbox = {6,0,w,h};
	TextInput*	textInput = new TextInput(hitbox);
	textInput->setColor(255,255,255);
	textInput->setPos(POSY_CENTER);
	this->addWidget(textInput);
	this->_input = textInput;
}

TextField::TextField(TextField const & src)
{
	*this = src;
}

TextField::~TextField(void)
{
	delete this->_input;
}

TextField & TextField::operator=(TextField const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void	TextField::onValidation(void (*validateFnct)(std::string const& text, void* arg), void* arg)
{
	this->_input->onValidation(validateFnct, arg);
}

void	TextField::setText(std::string const& text)
{
	this->_input->changeText(text);
}
