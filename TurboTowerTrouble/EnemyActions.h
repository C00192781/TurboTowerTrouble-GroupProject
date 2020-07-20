/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
/// DEPRECATED CODE
///	Contributors: Kevin Boylan, Matthew Watson
////////////////////////////////////////////////////////////
#pragma once
#include "BaseEnemy.h"
class EnemyActions :
	public BaseEnemy
{
private:
	//vector of waypoints, assumed will be used for pathfinding
	std::vector<sf::Vector2f> m_WaypointList;
	int previousWaypoint, nextWaypoint;
	//health of the enemy
	int health;
public:
	EnemyActions();
	void update();
	float getNewAngle();
	//
	void EnemyHit();
	~EnemyActions();
};

