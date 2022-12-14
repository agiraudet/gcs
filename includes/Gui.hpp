/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gui.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:28:56 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 09:43:18 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_HPP
# define GUI_HPP

# include "Elem.hpp"

class	Gui : public Elem
{
	public:
		Gui(SDL_Renderer* ren, int x, int y, int w, int h);
		Gui(Gui const & src);
		~Gui(void);

	public:
		void	render(void);
		
	private:
		Gui(void);
		Gui & operator=(Gui const & rhs);

	private:
		SDL_Texture	*_guiTex;
};

#endif
