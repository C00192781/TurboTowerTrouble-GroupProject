#pragma once
#include "BaseTower.h"
class TowerGraphics :
	public BaseTower
{
private:
	//2d texture for the tower.
	sf::Texture m_Texture;
	//sprite for the tower.
	sf::Sprite m_Sprite;
	//speed of rotation
	float rotateSpeed;
	std::pair<int, bool> rotateToPoint;
	void setTowerRotationAngle(sf::Vector2f enemyPos);
	bool rotateTower();
public:
	TowerGraphics();
	void update();
	bool RotateToEnemy();
	~TowerGraphics();
};

