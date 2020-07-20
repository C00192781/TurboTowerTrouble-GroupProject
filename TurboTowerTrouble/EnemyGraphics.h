#pragma once
// DEPRECATED CODE
#include "BaseEnemy.h"
class EnemyGraphics :
	public BaseEnemy
{
private:
	//2d texture for the enemy
	sf::Texture m_texture;
	//sprite for the enemy
	sf::Sprite m_sprite;


public:
	EnemyGraphics();
	~EnemyGraphics();
};

