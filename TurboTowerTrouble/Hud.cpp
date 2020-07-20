#include "Hud.h"

Hud::Hud()
{	
	hudTexture.loadFromFile(".\\Sprites folder\\TowerDefenceUI.png");
	hudSprite.setTexture(hudTexture);
	if (font.loadFromFile("MotorwerkOblique.ttf"))
	{

	}
	
	scoreDisplay.setFont(font);
	scoreDisplay.setCharacterSize(20);
	scoreDisplay.setColor(sf::Color::White);
	scoreDisplay.setPosition(820, 70);
	scoreDisplay.setString("TEST");

	currencyDisplay.setFont(font);
	currencyDisplay.setPosition(sf::Vector2f(950, 70));
	currencyDisplay.setColor(sf::Color::White);
	currencyDisplay.setString("TEST");
	
	BaseHealth.setFont(font);
	BaseHealth.setColor(sf::Color::White);
	BaseHealth.setPosition(sf::Vector2f(940, 210));
	BaseHealth.setCharacterSize(20);	
}
void Hud::Update(std::shared_ptr<int> currency, std::shared_ptr<int> score, int BHealth)
{
	std::string cur= std::to_string(*currency);
	currencyDisplay.setString("" + cur);
	cur = std::to_string(*score);
	scoreDisplay.setString("" + cur);
	cur = std::to_string(BHealth);
	BaseHealth.setString("" + cur);
}

// Uses to draw sprites in our HUD
void Hud::Draw(sf::RenderWindow *window)
{
	currencyDisplay.setFont(font);
	hudSprite.setTexture(hudTexture);

	window->draw(hudSprite);
	window->draw(currencyDisplay);
	window->draw(scoreDisplay);	
	window->draw(BaseHealth);
}

Hud::~Hud()
{
}