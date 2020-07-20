#pragma once
#include "SFML\Graphics.hpp"
////////////////////////////////
// \brief simply displays a string 
//
// Contributors: Kevin Boylan 
///////////////////////////////
class GameOverScreen
{
private:
	sf::Text tx;
	sf::Font fn;
	std::string str;
public:
	GameOverScreen();
	void Draw(sf::RenderWindow *window);
	~GameOverScreen();
};

