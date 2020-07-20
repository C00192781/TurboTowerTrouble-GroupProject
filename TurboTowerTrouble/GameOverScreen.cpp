#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	fn.loadFromFile("MotorwerkOblique.ttf");
	str = "Game over, You lose! Thank you for playing!";
	tx.setFont(fn);
	tx.setString(str);
	tx.setCharacterSize(40);
}
void GameOverScreen::Draw(sf::RenderWindow *window)
{
	window->draw(tx);
}

GameOverScreen::~GameOverScreen()
{
}
