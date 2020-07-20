#pragma once
#include "BaseTower.h"
class TowerPhysics :
	public BaseTower
{
private:
	//radius around the tower that will target enemies.
	float Attack_radius;
	//time it takes to reload
	int max_reloadTime;
	//time until reload complete
	int reloadTime;
	//list of enemies, used for finding if within attack radius and then to aim
	std::vector<std::shared_ptr<BaseEnemy>> EnemyList;


public:
	TowerPhysics();
	//(proposing having an upgrade to have intelligent aiming, so aiming at the highest threat enemy)
	//returns nearest enemy to aim to
	sf::Vector2f getNearestEnemy();
	~TowerPhysics();
};

