#pragma once
#include <SFML\Graphics.hpp>
////// token particle class
///// made by Dermot Mac Conville
////
class Particle
{
private:
	sf::Vector2f startPos;
	sf::RectangleShape shape;
	sf::Vector2f pos;
	sf::Vector2f force;
	float gravity;
	sf::Color col;
	float bounciness;
	float resistance;
public:
	Particle();
	Particle(sf::Vector2f impulse, sf::Vector2f position, sf::Color clr);
	void Update(sf::Vector2f impulse);
	void Ybounce(bool top);
	void Xbounce(bool left);
	void draw(sf::RenderWindow *w);
	void reset(sf::Vector2f spawn);
	int timer;
	bool dead;
	~Particle();
};

