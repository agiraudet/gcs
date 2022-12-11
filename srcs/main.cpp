/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:57:37 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 14:36:56 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bloc.hpp"
#include "utils.hpp"
#include "Label.hpp"
#include "Button.hpp"
#include "Root.hpp"

void	waitInput(Root& root, bool& loop)
{
	SDL_Event	event;

	while (loop)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		else if (event.type == SDL_KEYDOWN)
			break;
		root.passEvent(event);
		root.render();
		SDL_Delay(10);
	}
}

void	toggleLoop(void *arg)
{
	bool*	loop = (bool*)arg;

	if (*loop)
		*loop = false;
	else
		*loop = true;
}

int main(void)
{
	Root	root;
	bool	loop = true;

	Bloc*	bloc = new Bloc(50, 200, 300, 150);
	root.addWidget(bloc);

	Button	butt3(0, -5, 70, 20);
	butt3.colorOn = Color(50,50,50);
	butt3.colorOff = Color(75,75,75);
	butt3.pos = POSY_BOTTOM | POSX_CENTER;
	bloc->addWidget(&butt3);

	Bloc*	bloc2 = new Bloc(20, 20, 20, 20);
	bloc2->color = Color(0,255,0);
	bloc->addWidget(bloc2);

	Label*	label = new Label("Hello world!", 20, 10, 10);
	label->color = Color(255,0,0);
	root.addWidget(label);

	Label*	lab2 = new Label("TEST", 16, 10, 30);
	lab2->color = Color(255,0,0);
	root.addWidget(lab2);

	Button*	butt1 = new Button(500, 300, 100, 50);
	butt1->colorOn = Color(50,50,50);
	butt1->colorOff = Color(75,75,75);
	root.addWidget(butt1);

	Label*	buttLab = new Label("OK", 18, 0, 0);
	buttLab->color = Color(0,0,0);
	buttLab->pos = POSX_RIGHT | POSY_BOTTOM;
	butt1->addWidget(buttLab);

	Button*	buttQuit = new Button(335, 420, 100, 50);
	buttQuit->colorOn = Color(50,50,50);
	buttQuit->colorOff = Color(75,75,75);
	buttQuit->onClic(&toggleLoop, (void*)&loop);
	root.addWidget(buttQuit);

	Label*	quitLab = new Label("Quit", 22, 0, 0);
	quitLab->color = Color(0,0,0);
	quitLab->pos = POSX_CENTER | POSY_CENTER;
	buttQuit->addWidget(quitLab);

	waitInput(root, loop);
	return 0;
}
