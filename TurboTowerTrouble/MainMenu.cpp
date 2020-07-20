#include "MainMenu.h"
#include <iostream>
#include <algorithm>
MainMenu::MainMenu()
{
	std::cout << "default constructor called" << std::endl;
}

MainMenu::MainMenu(sf::Texture tx, sf::Font fn, std::shared_ptr <bool> pExit, std::shared_ptr <bool> pRunning) : font(&fn), buttonImage(&tx),
Manager(buttonVectors, *font, *buttonImage), templateButton("template", sf::Vector2f(100, 100), tx, fn), exit(pExit), gameRunning(pRunning)
{
	Manager.totalButtonCount = 0;

	buttonVectors.push_back(templateButton);
	Manager.MakeNewButton("Play game", sf::Vector2f(100, 300));
	Manager.MakeNewButton("options", sf::Vector2f(100, 350));
	Manager.MakeNewButton("Exit", sf::Vector2f(100, 400));

}
//used for the pause menu
MainMenu::MainMenu(sf::Texture tx, sf::Font fn) : font(&fn), buttonImage(&tx),
Manager(buttonVectors, *font, *buttonImage), templateButton("template", sf::Vector2f(100, 100), tx, fn)
{
	buttonVectors.push_back(templateButton);
	Manager.MakeNewButton("Resume", sf::Vector2f(100, 300));
	Manager.MakeNewButton("Restart", sf::Vector2f(100, 350));
	Manager.MakeNewButton("Exit", sf::Vector2f(100, 400));

}
void MainMenu::update()
{
//	m_currentButton = ButtonSelection(m_currentButton);
	Manager.update(&buttonVectors);
	sf::Joystick::update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Joystick::isButtonPressed(0, 0))//0=A 1=B 2=X 3=Y 4=LB 5=RB 6=Back 7=Start
	{

		if (Manager.getButtonName(&buttonVectors) == "Exit")
		{
			Message = "Exit";
		}
		if (Manager.getButtonName(&buttonVectors) == "Play game")
		{
			Message = "Build";
		}
		if (Manager.getButtonName(&buttonVectors) == "Resume")
		{
			Message = "Resume"; 
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//use this for doing pause stuff
	{
		Message = "Pause";
	}

}


void MainMenu::draw(sf::RenderWindow* window)
{
	for (int i = 1; i < buttonVectors.size(); i++)//start at 1, so template button isn't drawn or updated
	{
		buttonVectors.at(i).draw(window);
	}
}
