#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <memory>
/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Kevin Boylan, Matthew Watson, Dermot Mac Conville
////////////////////////////////////////////////////////////
class Hud
{
private:
	sf::Texture hudTexture;
	sf::Sprite hudSprite;
	sf::Font font;
	sf::Text currencyDisplay;
	sf::Text scoreDisplay;
	sf::Text BaseHealth;


public:
	Hud();
	void Update(std::shared_ptr<int> currency, std::shared_ptr<int> score, int BHealth);
	void Draw(sf::RenderWindow *window);
	~Hud();
};