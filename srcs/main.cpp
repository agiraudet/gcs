/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:22:37 by agiraude          #+#    #+#             */
/*   Updated: 2022/12/09 13:12:52 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Root.hpp"
#include "Frame.hpp"
#include "Button.hpp"
#include <unistd.h>
#include <iostream>

void	waitInput(Root& root)
{
	SDL_Event	event;

	for(;;)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		else if (event.type == SDL_KEYDOWN)
			break;
		else
			root.processEvent(event);
		SDL_Delay(10);
	}
}

void	triggerTest1(void* arg)
{
	Frame*	frame = (Frame*)arg;

	frame->setColor(100,100,100);
	frame->draw();
	std::cout << "test clic 1" << std::endl;
}

void	triggerTest2(void* arg)
{
	Frame*	frame = (Frame*)arg;

	frame->setColor(200,200,200);
	frame->draw();
	std::cout << "test clic 2" << std::endl;
}

int main(void)
{
	Root	root;
	Frame* frame1 = new Frame(Rect(50,50,250,100), "frame1");
	Button*	butt1 = new Button(Rect(10, 10, 200, 30), "OK1");
	Button*	butt2 = new Button(Rect(10, 10, 200, 30), "OK2");
	Button*	butt3 = new Button(Rect(10, 50, 200, 30), "OK3");

	butt1->setColor(255,0,0);
	butt1->setColorAction(0,255,0);

	butt3->setColor(255,0,0);
	butt3->setColorAction(0,0,255);

	frame1->addChild(butt1);
	frame1->addChild(butt3);
	//frame1->setVis(false);

	butt2->setColor(255,0,0);
	butt2->setColorAction(0,255,0);


	butt1->setAction(&triggerTest1, frame1);
	butt2->setAction(&triggerTest2, frame1);

	root.addWidget(butt2);
	root.addWidget(frame1);

	root.update();
	waitInput(root);
	
	return 0;
}
