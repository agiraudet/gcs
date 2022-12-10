/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:38:07 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 10:19:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

class Widget;

enum	watchEvent
{
	NEVER	= 1 << 0,
	ALWAYS	= 1 << 1,
	INSIDE	= 1 << 2,
	OUTSIDE	= 1 << 3
};

bool	collide(int x, int y, Widget* widget);

#endif
