/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exampleRoot.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:57:37 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/14 16:20:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bloc.hpp"
#include "utils.hpp"
#include "Label.hpp"
#include "Button.hpp"
#include "Frame.hpp"
#include "Root.hpp"
#include "TextField.hpp"
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
		bloc->color = Color(0,255,0);
	else
		bloc->color = Color(0,0,255);
	bloc->redraw();
	i ^= 1;
}

void	toggleVis(void*arg)
{
	Widget*	widget = (Widget*)arg;

	widget->setVisAll(!widget->getVis());
}


void	printText(std::string const& text, void* arg)
{
	std::cout << text << std::endl;
}

int main(void)
{
	bool	loop = true;
	Root	root(720, 480);

	Label	title("GCSI EXAMPLE", 25, 0, 10, 0);
	title.color = Color(255,255,255);
	title.pos = POSX_CENTER | POSY_TOP;
	root.addWidget(&title);

	Bloc	bloc1(10, 0, 200, 400);
	bloc1.color = Color(200,200,200);
	bloc1.pos = POSY_CENTER | POSX_LEFT;
	root.addWidget(&bloc1);

	Label	bloc1Label("Bloc 1", 20, 0, 10, 0);
	bloc1Label.color = Color(255,0,255);
	bloc1Label.pos = POSY_TOP | POSX_CENTER;
	bloc1.addWidget(&bloc1Label);

	Bloc	bloc2(0, 0, 50, 50);
	bloc2.color = Color(255,255,255);
	bloc2.pos = POSX_CENTER | POSY_CENTER;
	root.addWidget(&bloc2);

	int	yPos = 60;
	for (int i = 0; i < 5; i++)
	{
		Button*	butt = new Button(0, yPos, 100, 20);
		butt->pos = POSY_TOP | POSX_CENTER;
		butt->onClic(&changeColor, (void*)&bloc2);
		bloc1.addWidget(butt);

		Label	*lab = new Label("button", 16, 0, 0, 0);
		lab->color = Color(0,0,0);
		lab->pos = POSY_CENTER | POSX_CENTER;
		butt->addWidget(lab);

		yPos += 25;
	}

	Bloc	bloc4(-5, 0, 200, 400);
	bloc4.color = Color(200,100,0);
	bloc4.setVis(false);
	bloc4.pos = POSX_RIGHT | POSY_CENTER;
	root.addWidget(&bloc4);

	Label	bloc4Label("Bloc 2", 20, 0, -10, 0);
	bloc4Label.color = Color(0,255,0);
	bloc4Label.pos = POSY_BOTTOM | POSX_CENTER;
	bloc4Label.setVis(false);
	bloc4.addWidget(&bloc4Label);

	Button*	buttToggle = new Button(0, -10, 100, 50);
	buttToggle->pos = POSX_CENTER | POSY_BOTTOM;
	buttToggle->colorOn = Color(50,50,50);
	buttToggle->colorOff = Color(30,30,30);
	buttToggle->onClic(&toggleVis, (void*)&bloc4);
	root.addWidget(buttToggle);

	Label*	quitLab = new Label("toggle", 22, 0, 0, 0);
	quitLab->color = Color(255,0,0);
	quitLab->pos = POSX_CENTER | POSY_CENTER;
	buttToggle->addWidget(quitLab);

	Button quit(-5,5,30,30);
	quit.colorOn = Color(130,130,130);
	quit.colorOff = Color(155,150,150);
	quit.pos = POSX_RIGHT | POSY_TOP;
	quit.onClic(&toggleLoop, (void*)&loop);
	
	Label	b3lab("X", 28, 0, 0, 0);
	b3lab.pos = POSX_CENTER | POSY_CENTER;
	b3lab.color = Color(0,0,0);

	root.addWidget(&quit);
	quit.addWidget(&b3lab);

	TextField	text(0, 180, 150, 26);
	text.color = Color (255,255,0);
	text.pos = POSX_CENTER;
	text.onValidation(&printText, NULL);
	root.addWidget(&text);

	waitInput(root, loop);
	return 0;
}
