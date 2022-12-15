/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exampleRoot.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:57:37 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/15 16:19:45 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcs.hpp"
#include <iostream>
#include <string>

void	waitInput(Root& root, bool& loop)
{
	SDL_Event	event;

	root.render();
	while (loop)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		root.passEvent(event, 0,0);
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

void	changeColor(void *arg)
{
	static int	i = 0;
	Bloc*	bloc = (Bloc*)arg;

	if (i)
		bloc->setColor(0,255,0);
	else
		bloc->setColor(0,0,255);
	bloc->redraw();
	i ^= 1;
}

void	toggleVis(void*arg)
{
	Widget*	widget = (Widget*)arg;

	widget->setVis(!widget->getVis());
}


void	printText(std::string const& text, void* arg)
{
	std::cout << text << std::endl;
}

int main(void)
{
	bool	loop = true;
	Root	root(720, 480);

	Label	title("GCS EXAMPLE", 25, 0, 10, 0);
	title.setColor(255,255,255);
	title.setPos(POSX_CENTER | POSY_TOP);
	root.addWidget(&title);

	Bloc	bloc1(10, 0, 200, 400);
	bloc1.setColor(200,200,200);
	bloc1.setPos(POSY_CENTER | POSX_LEFT);
	root.addWidget(&bloc1);

	Label	bloc1Label("Bloc 1", 20, 0, 10, 0);
	bloc1Label.setColor(255,0,255);
	bloc1Label.setPos(POSY_TOP | POSX_CENTER);
	bloc1.addWidget(&bloc1Label);

	Bloc	bloc2(0, 0, 50, 50);
	bloc2.setColor(255,255,255);
	bloc2.setPos(POSX_CENTER | POSY_CENTER);
	root.addWidget(&bloc2);

	int	yPos = 60;
	for (int i = 0; i < 5; i++)
	{
		Button*	butt = new Button(0, yPos, 100, 20);
		butt->setPos(POSY_TOP | POSX_CENTER);
		butt->onClic(&changeColor, (void*)&bloc2);
		bloc1.addWidget(butt);

		Label	*lab = new Label("button", 16, 0, 0, 0);
		lab->setColor(0,0,0);
		lab->setPos(POSY_CENTER | POSX_CENTER);
		butt->addWidget(lab);

		yPos += 25;
	}

	Bloc	bloc4(-5, 0, 200, 400);
	bloc1.setColor(200,200,200);
	bloc4.setVis(false);
	bloc4.setPos(POSX_RIGHT | POSY_CENTER);
	root.addWidget(&bloc4);

	Label	bloc4Label("Bloc 2", 20, 0, -10, 0);
	bloc4Label.setColor(0,255,0);
	bloc4Label.setPos(POSY_BOTTOM | POSX_CENTER);
	bloc4.addWidget(&bloc4Label);

	Button*	buttToggle = new Button(0, -10, 100, 50);
	buttToggle->setPos(POSX_CENTER | POSY_BOTTOM);
	buttToggle->setColorOn(50,50,50);
	buttToggle->setColor(30,30,30);
	buttToggle->onClic(&toggleVis, (void*)&bloc4);
	root.addWidget(buttToggle);

	Label*	quitLab = new Label("toggle", 22, 0, 0, 0);
	quitLab->setColor(255,0,0);
	quitLab->setPos(POSX_CENTER | POSY_CENTER);
	buttToggle->addWidget(quitLab);

	Button quit(-5,5,30,30);
	quit.setColorOn(155,150,150);
	quit.setPos(POSX_RIGHT | POSY_TOP);
	quit.onClic(&toggleLoop, (void*)&loop);
	
	Label	b3lab("X", 28, 0, 0, 0);
	b3lab.setPos(POSX_CENTER | POSY_CENTER);
	b3lab.setColor(0,0,0);

	root.addWidget(&quit);
	quit.addWidget(&b3lab);

	TextField	text(0, 180, 150, 26);
	text.setColor (255,255,0);
	text.setPos(POSX_CENTER);
	text.onValidation(&printText, NULL);
	root.addWidget(&text);

	waitInput(root, loop);
	return 0;
}
