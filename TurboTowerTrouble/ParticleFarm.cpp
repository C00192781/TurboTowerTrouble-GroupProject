#include "ParticleFarm.h"


ParticleFarm::ParticleFarm()
{

	for (int i = 0; i < 2; i++)
	{
		particles[i] = Particle(sf::Vector2f(0, 0), sf::Vector2f(200, 200), sf::Color::Red);
	}
}
void ParticleFarm::update()
{

	for (int i = 0; i < 2; i++)
	{
		if (particles[i].dead)
		{
			particles[i].reset(spawnDir);
		}
		if (particles[i].dead == false)
		{
			particles[i].Update(impulse);
		}
	}
}

void ParticleFarm::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < 2; i++)
	{
		if (particles[i].dead == false)
		{
			particles[i].draw(window);
		}
	}
}

ParticleFarm::~ParticleFarm()
{
}
