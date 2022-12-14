/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:42:59 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 10:48:48 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Button_HPP
# define Button_HPP

# include "Widget.hpp"
# include "Color.hpp"

class	Button : public Widget
{
	public:
		Button(int x, int y, int w, int h);
		Button(Button const & src);
		~Button(void);
		
	public:
		Button & operator=(Button const & rhs);

	public:
		void	act(SDL_Event const& event, int offsetX, int offsetY);
		void	onClic(void (*clicFnct)(void *arg), void* arg);

	private:
		Button(void);
	
	private:
		void	_draw(void);
		void	_createTex(void);
	
	private:
		SDL_Texture*	_texOn;
		SDL_Texture*	_texOff;
		void*			_clicArg;
		void			(*_clicFnct)(void* arg);
	
	public:
		Color	colorOff;
		Color	colorOn;
};

#endif
