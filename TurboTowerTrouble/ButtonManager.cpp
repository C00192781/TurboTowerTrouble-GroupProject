#include "ButtonManager.h"
#include <iostream>
ButtonManager::ButtonManager()
{

}
ButtonManager::ButtonManager(std::vector<Button> &btn, sf::Font &fn, sf::Texture &tx) :btnVector(&btn), font(&fn), texture(&tx), totalButtonCount(0)
{
	buttonPressed = false;
	selected = 0;
	buttonMove.loadFromFile(".\\Sound Effects\\menuMove.wav");
}
void ButtonManager::MakeNewButton(std::string text, sf::Vector2f pos)
{
	Button temp = btnVector->at(0);
	temp.setString(text);
	temp.setPos(pos);
	temp.selected = false;
	btnVector->push_back(temp);
	totalButtonCount++;
	btnVector->at(totalButtonCount).loadThings();
}
void ButtonManager::update(std::vector<Button>* buttonPointer)
{
	sound.setBuffer(buttonMove);
	padInput = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY));
	sf::Joystick::update();
	if ((padInput.y == 100 && selected > 1) && buttonPressed == false)
	{
		buttonPressed = true;
		buttonPointer->at(selected).selected = false;//deselects previous button

		selected--;
		buttonPointer->at(selected).selected = true;//selects current button
		if (sound.getStatus() == sf::Sound::Status::Stopped)
		{
			sound.play();
		}
	}
	else if ((padInput.y == -100 && selected < totalButtonCount) && buttonPressed == false)
	{
		buttonPressed = true;
		buttonPointer->at(selected).selected = false;//deselects previous button
		if (selected++ > totalButtonCount)//this is here to prevent crashes
			selected--;
		buttonPointer->at(selected).selected = true;//selects current button
		if (sound.getStatus() == sf::Sound::Status::Stopped)
		{
			sound.play();
		}
	}
	if (padInput.y>-100 && padInput.y < 100)
	{
		buttonPressed = false;
	}
	if (sf::Joystick::isButtonPressed(0, 0))//0=A 1=B 2=X 3=Y 4=LB 5=RB 6=Back 7=Start
	{
		// yes: shoot!
		std::cout << "butn" << std::endl;//debug thing for button inputs
	}


	timer++;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (timer >= 30)
		{
			if (selected > 1)
			{
				buttonPointer->at(selected).selected = false;//deselects previous button

				selected--;
				buttonPointer->at(selected).selected = true;//selects current button
				if (sound.getStatus() == sf::Sound::Status::Stopped)
				{
					sound.play();
				}
				timer = 0;
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (timer >= 30)
		{
			if (selected < totalButtonCount)
			{
				buttonPointer->at(selected).selected = false;//deselects previous button
				if (selected++ > totalButtonCount && timer == 1)//this is here to prevent crashes
					selected--;
				buttonPointer->at(selected).selected = true;//selects current button

				if (sound.getStatus() == sf::Sound::Status::Stopped)
				{
					sound.play();
				}
				timer = 0;
			}
		}
	}

	for (int i = 1; i < buttonPointer->size(); i++)
	{//cycles through the buttons and updates
		buttonPointer->at(i).update();
	}
}
std::string ButtonManager::getButtonName(std::vector<Button>* buttonPointer)
{
	return buttonPointer->at(selected).String();
}
ButtonManager::~ButtonManager()
{
	btnVector->clear();
	btnVector->shrink_to_fit();
}
