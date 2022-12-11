/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:57:37 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/11 16:00:39 by agiraude         ###   ########.fr       */
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

void	changeColor(void *arg)
{
	static int	i = 0;
	Bloc*	bloc = (Bloc*)arg;

	if (i % 2)
		bloc->color = Color(0,255,0);
	else
		bloc->color = Color(0,0,255);
	bloc->draw();
	i++;
}

int main(void)
{
	bool	loop = true;
	Root	root(720, 480);

	Label	title("GCSI EXAMPLE", 25, 10, 0);
	title.color = Color(255,255,255);
	title.pos = POSX_CENTER | POSY_TOP;
	root.addWidget(&title);

	Bloc	bloc1(10, 0, 200, 400);
	bloc1.color = Color(200,200,200);
	bloc1.pos = POSY_CENTER | POSX_LEFT;
	root.addWidget(&bloc1);

	Label	bloc1Label("Bloc 1", 20, 0, 10);
	bloc1Label.color = Color(0,0,0);
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

		Label	*lab = new Label("button", 16, 0, 0);
		lab->color = Color(0,0,0);
		lab->pos = POSY_CENTER | POSX_CENTER;
		butt->addWidget(lab);

		yPos += 25;
	}

	Button*	buttQuit = new Button(0, -10, 100, 50);
	buttQuit->pos = POSX_CENTER | POSY_BOTTOM;
	buttQuit->colorOn = Color(50,50,50);
	buttQuit->colorOff = Color(30,30,30);
	buttQuit->onClic(&toggleLoop, (void*)&loop);
	root.addWidget(buttQuit);

	Label*	quitLab = new Label("Quit", 22, 0, 0);
	quitLab->color = Color(255,0,0);
	quitLab->pos = POSX_CENTER | POSY_CENTER;
	buttQuit->addWidget(quitLab);

	waitInput(root, loop);
	return 0;
}
