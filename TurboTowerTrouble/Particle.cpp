#include "Particle.h"
Particle::Particle()
{

}

Particle::Particle(sf::Vector2f impulse = sf::Vector2f(0, 20), sf::Vector2f position = sf::Vector2f(300, 300), sf::Color clr = sf::Color(255, 255, 255, 255)) :
force(impulse), pos(position), startPos(position), col(clr)
{
	shape.setFillColor(clr);
	shape.setPosition(pos);
	shape.setSize(sf::Vector2f(10, 10));
	timer = 600;
	bounciness = -0.5f;
	dead = false;
	gravity = 0.1f;
	force.x += 5;
	resistance = 0.02f;
}
void Particle::Update(sf::Vector2f impulse)
{
	timer--;
	force += impulse;
	if (force.x < 0)
		resistance = -0.02f;
	else
	{
		resistance = 0.02f;
	}
	force.x -= resistance;
	force.y += gravity;
	if (pos.y > 710)
	{
		Ybounce(false);
	}

	pos += force;
	if (timer<0)
	{
		dead = true;
	}
	force -= impulse;

}
void Particle::reset(sf::Vector2f spawn)
{
	dead = false;
	pos = startPos;
	timer = 600;
	gravity = 0.1f;
	force.x = 5;
	force.y = 0;
}
void Particle::Xbounce(bool left)
{
	force.x*=bounciness;
}
void Particle::Ybounce(bool top)
{
	force.y*=bounciness;
	if (top == true)
	{
		pos.y = 0;
	}
	else
	{
	pos.y =710;
	}

}

void Particle::draw(sf::RenderWindow *window)
{
	shape.setPosition(pos);
	window->draw(shape);
}

Particle::~Particle()
{
}
