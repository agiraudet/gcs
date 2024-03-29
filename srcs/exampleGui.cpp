/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exampleGui.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:43:36 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 14:56:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gcs.hpp"

#define SCWD 720
#define SCHG 480

void	printText(std::string const& text, void* arg)
{
	TextField*	tf = (TextField*)arg;

	std::cout << text << std::endl;
	tf->setText("");
}

void	WaitInput(Gui& gui)
{
	SDL_Event	event;

	gui.render();

	for(;;)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		gui.passEvent(event, 0,0);
		gui.render();
		SDL_Delay(10);
	}
}

void	changeLabel(void *arg)
{
	Label*	lab = (Label*)arg;
	static	int i = 0;

	lab->setText((i ? "YO" : "this is a test"));
	i ^= 1;
}

int main()
{
	SDL_Window*		win;
	SDL_Renderer*	ren;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(1);
	win = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							SCWD, SCHG, 0);
	if (!win)
	{
		SDL_Quit();
		exit(2);
	}
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (!ren)
	{
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(3);
	}
	if (TTF_Init() < 0)
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
		exit(3);
	}
	

	Gui	gui(ren, 0, 0, SCWD / 2, SCHG);

	Bloc	bloc(0,50,200,200);
	bloc.setColor(255,255,0);
	bloc.setPos(POSX_RIGHT);
	gui.addWidget(&bloc);

	Label	label("Right aligned bloc", 16, 0, 0, 0);
	label.setPos(POSX_CENTER | POSY_TOP);
	label.setColor(255,0,0);
	bloc.addWidget(&label);

	Bloc	bloc2(5,-5,400,50);
	bloc2.setColor(255,0,0);
	bloc2.setPos(POSY_BOTTOM | POSX_LEFT);
	bloc.addWidget(&bloc2);

	Button	test(0,-5,50,50);
	test.setColorOn(200,200,200);
	test.setColor(100,100,100);
	test.onClic(&changeLabel, (void*)&label);
	test.setPos(POSX_CENTER | POSY_BOTTOM);

	Bloc	bloc3(0,30,60,300);
	bloc3.setColor(0,0,255);
	bloc3.setPos(POSX_LEFT);
	bloc3.addWidget(&test);
	gui.addWidget(&bloc3);

	TextField	f(20, -5, 150, 26);
	f.setPos(POSY_BOTTOM | POSX_LEFT);
	f.setColor(255,0,255);
	f.onValidation(&printText, &f);
	gui.addWidget(&f);

	WaitInput(gui);

	return 0;
}
