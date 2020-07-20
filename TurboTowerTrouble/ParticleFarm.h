#pragma once
#include "Particle.h"
///simple class to spawn particles
//Made by Dermot Mac Conville
class ParticleFarm
{
private:
	Particle particles[2];

	sf::Vector2f impulse;
	sf::Vector2f spawnDir;
	bool worthSpawning;
public:
	ParticleFarm();
	void update();
	void draw(sf::RenderWindow *window);
	~ParticleFarm();
};

