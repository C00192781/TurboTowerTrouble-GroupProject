////////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Simon Dowling, Kevin Boylan, Rolands Stafeckis
////////////////////////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
//#include "stdafx.h"
#include <cmath>
#include <math.h>
#include "Projectiles.h"
#include "SlowEnemy.h"
class BaseTower
{
private:

	//2d texture for the tower.
	sf::Texture m_texture;
	sf::SoundBuffer towerFire;
	sf::Sound sound;
	//speed of rotation
	sf::CircleShape m_circle;
	//circle to determine the range of the tower.
	std::pair<int, bool> rotateToPoint;
	void setTowerRotationAngle(sf::Vector2f enemyPos);
	void fireBullet(int &index);
	bool rotateTower();
	int m_fireCounter;
	int m_fireIndex;
public:
	BaseTower();
	enum class TowerType
	{
		Vanilla,
		SniperTurret,
		UziTurret
	};
	float m_damage;
	float m_range;
	TowerType type;
	Projectiles projectiles[20];
	std::vector<Projectiles> projectilesVector;

	BaseEnemy enemies;
	int m_fireRate;

	int m_maxProjectiles;
	BaseTower(sf::Texture &texture); //, TowerType type
	void update();
	bool RotateToEnemy();
	void draw(sf::RenderWindow *window);
	void setPosition(sf::Vector2f pos);
	void setProjectilePosition(sf::Vector2f);
	void setRange(float range);
	bool checkEnemyInRange(sf::Vector2f enemyPos);
	void targetEnemy(sf::Vector2f enemyPos);
	void requestFire(sf::Vector2f enemyPos);
	int checkCollision(std::shared_ptr<sf::Sprite> enemySprite, std::shared_ptr<int> health); // , int size
	sf::CircleShape getRangeIndicator();
	sf::Sprite getSprite();
	~BaseTower();
	int towerBaseIndex;
	bool alligned;
	//sprite for the tower.
	sf::Sprite m_sprite;

	float rotateSpeed;

	void TowerBaseUpgrade(TowerType type, sf::Texture &texture);
};

