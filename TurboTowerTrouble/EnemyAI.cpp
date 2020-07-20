////////////////////////////////////////////////////////////
// Name: Kevin Boylan
// Student ID: C00192781
////////////////////////////////////////////////////////////
#include "EnemyAI.h"
#include <iostream>
#include <memory>

EnemyAI::EnemyAI()
{

}

////////////////////////////////////////////////////////////
EnemyAI::EnemyAI(std::shared_ptr<std::vector<sf::Vector2f>> waypoints)
{
	// The waypoints for the enemies
	m_wayPoints = waypoints;
	xPath = false;
	yPath = false;
	index = 0;
};

////////////////////////////////////////////////////////////
/// \brief	Will be used to initialize variable values 
/// Note: none of these variables are currently being used, but I am
/// stating the intent of the method, and many of these variables will 
/// come into use
//////////////////////////////////////////////////////////////
void EnemyAI::initialize()
{

}

////////////////////////////////////////////////////////////
/// \brief updates the Enemy AI class. 
///  \param This is where the code for moving the towers (to their designated x and y waypoints) 
///  is currently executed
//////////////////////////////////////////////////////////////
sf::Vector2f EnemyAI::update(sf::Vector2f enemyPos)
{
	// ensures that movement we will only transition to the next waypoint once both the x and y parts of each waypoint have been reached
	if (yPath == true && xPath == true)
	{
		xPath = false;
		yPath = false;
		index++;
	}

	// outlines conditions for the position to adjust, in relation to the waypoint
	if (index < m_wayPoints->size())
	{
		if (enemyPos.x != m_wayPoints->at(index).x) // if the position isn't at the waypoint
		{
			if (enemyPos.x > m_wayPoints->at(index).x)  // if the position (for x) is greater than the waypoint going ->
			{
				enemyPos.x -= m_speed;  // then, the position will move left <-
			}

			if (enemyPos.x < m_wayPoints->at(index).x)  // if the position (for x) is less than the waypoint going <-
			{
				enemyPos.x += m_speed;  // then, the position will move right ->
			}
		}
		else
		{
			xPath = true;
		}

		if (enemyPos.y != m_wayPoints->at(index).y)
		{
			if (enemyPos.y > m_wayPoints->at(index).y)  // if the position (for x) is greater than the waypoint going ->
			{
				enemyPos.y -= m_speed;  // then, the position will move left <-
			}

			if (enemyPos.y < m_wayPoints->at(index).y)   // if the position (for x) is less than the waypoint going <-
			{
				enemyPos.y += m_speed;  // then, the position will move right ->
			}
		}
		else
		{
			yPath = true;
		}

		if (enemyPos.x > m_wayPoints->at(index).x - 20 && enemyPos.x < m_wayPoints->at(index).x + 20)
		{
			xPath = true;    // when the position for the x axis is reached (within a standard deviation of 1) for the waypoint, this bool is set to true
		}

		if (enemyPos.y > m_wayPoints->at(index).y + 20 && enemyPos.y < m_wayPoints->at(index).y + 20)
		{
			yPath = true;     // when the position for the y axis is reached (within a standard deviation of 1) for the waypoint, this bool is set to true
		}
	}
	return enemyPos;
}
