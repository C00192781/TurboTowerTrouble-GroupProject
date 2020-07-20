////////////////////////////////////////////////////////////
// BaseEnemy class for others to inherit from.
// Contributors: Simon Dowling, Kevin Boylan, Matthew Watson
//
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <cmath>
#include <math.h>
#include <memory>
#include "EnemyAI.h"
//#include "stdafx.h"
class BaseEnemy
{
protected:

	//health of the enemy
	int m_health;
	//speed of the enemy
	int m_speed;
	//angle of rotation, used for moving from point to point and rotating sprite
	float m_angle;
	int DIRECTION;
	sf::Sprite m_sprite; 
	sf::Texture m_texture;
	sf::RectangleShape m_healthBar; //a UI element so the player will know how much health the peep has.
	sf::Vector2f m_position;
	std::shared_ptr<sf::Vector2f> pPosition;
	EnemyAI m_enemyAI;

public:
	BaseEnemy();
	enum class EnemyType
	{
		Slow,
		Medium,
		Fast
	};
	EnemyType type;
	BaseEnemy(std::shared_ptr<sf::Texture> texture, EnemyType type,std::shared_ptr<std::vector<sf::Vector2f>> waypoints);
	//update loop, stuff goes here
	void update();
	void resolveCollisions(); //maybe pass a bullet type in here to determine damage/slows
	void draw(sf::RenderWindow *window);
	sf::Vector2f getPosition();
	std::shared_ptr<int> getHealthPointer();
	std::shared_ptr<sf::Sprite>getEnemySprite();
	int getHealth();
	void setHealth(int health);
	~BaseEnemy();
};

