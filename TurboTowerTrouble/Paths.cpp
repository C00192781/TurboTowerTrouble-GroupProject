#include "Paths.h"

std::shared_ptr<std::vector<sf::Vector2f>> Paths::getPath(int mapCount, int firstPath, int secondPath)
{
	// Create a shared pointer to a vector of waypoints
	std::shared_ptr<std::vector<sf::Vector2f>> waypoints;
	// We reset the waypoints - avoids breaks
	waypoints.reset(new std::vector<sf::Vector2f>());

	// waypoints are added to the vector if some of the parameters
	// that have been passed in are true
	if (mapCount == 1)
	{
		if (firstPath == 1)
		{
			waypoints->push_back(sf::Vector2f(80, 230));

		}
		else if (firstPath == 2)
		{
			//only one first path on this map
		}


		if (secondPath == 1)
		{
			waypoints->push_back(sf::Vector2f(80, 55));
			waypoints->push_back(sf::Vector2f(520, 55));
			waypoints->push_back(sf::Vector2f(520, 230));
			waypoints->push_back(sf::Vector2f(700, 230));
		}
		else if (secondPath == 2)
		{
			waypoints->push_back(sf::Vector2f(80, 405));
			waypoints->push_back(sf::Vector2f(520, 405));
			waypoints->push_back(sf::Vector2f(520, 230));
			waypoints->push_back(sf::Vector2f(700, 230));
		}
	}
	if (mapCount == 2)
	{
		if (firstPath == 1)
		{
			waypoints->push_back(sf::Vector2f(-7, 130));
			waypoints->push_back(sf::Vector2f(60, 100));
			waypoints->push_back(sf::Vector2f(200, 100));

		}
		else if (firstPath == 2)
		{
			//only one first path on this map
			waypoints->push_back(sf::Vector2f(-15, 530));
			waypoints->push_back(sf::Vector2f(270, 530));
		}

		if (firstPath==1&&secondPath == 1)
		{
			waypoints->push_back(sf::Vector2f(200, 100));
			waypoints->push_back(sf::Vector2f(560, 100));
			waypoints->push_back(sf::Vector2f(560, 260));
			waypoints->push_back(sf::Vector2f(800, 260));
		}
		else if (firstPath == 1 && secondPath == 2)
		{
			waypoints->push_back(sf::Vector2f(200, 100));
			waypoints->push_back(sf::Vector2f(200, 230));
			waypoints->push_back(sf::Vector2f(530, 230));
			waypoints->push_back(sf::Vector2f(560, 260));
			waypoints->push_back(sf::Vector2f(800, 260));
		}
		else if (firstPath==2&&secondPath == 1)
		{
			waypoints->push_back(sf::Vector2f(290,400));
			waypoints->push_back(sf::Vector2f(560,400));
			waypoints->push_back(sf::Vector2f(560,260));
			waypoints->push_back(sf::Vector2f(800,260));
		}
		else if (firstPath == 2 && secondPath == 2)
		{
			waypoints->push_back(sf::Vector2f(690, 530));
			waypoints->push_back(sf::Vector2f(690, 260));
			waypoints->push_back(sf::Vector2f(800, 260));
		}
	}
	if (mapCount == 3)
	{
		if (firstPath == 1)
		{
			waypoints->push_back(sf::Vector2f(125, 200));
			waypoints->push_back(sf::Vector2f(125, 135));
			waypoints->push_back(sf::Vector2f(200, 135));
			waypoints->push_back(sf::Vector2f(200, -50));
			waypoints->push_back(sf::Vector2f(660, -50));
			waypoints->push_back(sf::Vector2f(660, 145));
			waypoints->push_back(sf::Vector2f(760, 145));
			waypoints->push_back(sf::Vector2f(760, 275));
			waypoints->push_back(sf::Vector2f(810, 275));

		}
		else if (secondPath == 1)
		{
			////only one first path on this map
			waypoints->push_back(sf::Vector2f(125, 275));
			waypoints->push_back(sf::Vector2f(125, 350));
			waypoints->push_back(sf::Vector2f(200, 350));
			waypoints->push_back(sf::Vector2f(200, 400));
			waypoints->push_back(sf::Vector2f(200, 450));
			waypoints->push_back(sf::Vector2f(650, 450));
			waypoints->push_back(sf::Vector2f(650, 350));
			waypoints->push_back(sf::Vector2f(680, 350));
			waypoints->push_back(sf::Vector2f(760, 350));
			waypoints->push_back(sf::Vector2f(760, 275));
			waypoints->push_back(sf::Vector2f(810, 275));
			
		}

		if (firstPath == 1 && secondPath == 1)
		{
			waypoints->push_back(sf::Vector2f(20, 500));
			waypoints->push_back(sf::Vector2f(660, 500));
			waypoints->push_back(sf::Vector2f(680, 350));
			waypoints->push_back(sf::Vector2f(760, 350));
			waypoints->push_back(sf::Vector2f(400, 275));
			waypoints->push_back(sf::Vector2f(680, 275));
			waypoints->push_back(sf::Vector2f(760, 275));
			waypoints->push_back(sf::Vector2f(810, 275));
		}
		else if (firstPath == 1 && secondPath == 2)
		{
			waypoints->push_back(sf::Vector2f(20, 500));
			waypoints->push_back(sf::Vector2f(660, 500));
			waypoints->push_back(sf::Vector2f(680, 350));
			waypoints->push_back(sf::Vector2f(760, 350));
			waypoints->push_back(sf::Vector2f(400, 275));
			waypoints->push_back(sf::Vector2f(680, 275));
			waypoints->push_back(sf::Vector2f(760, 275));
			waypoints->push_back(sf::Vector2f(810, 275));
		}
		
		else if (firstPath == 2 && secondPath == 1)
		{
			waypoints->push_back(sf::Vector2f(125, 275));
			waypoints->push_back(sf::Vector2f(125, 350));
			waypoints->push_back(sf::Vector2f(200, 350));
			waypoints->push_back(sf::Vector2f(200, 400));
			waypoints->push_back(sf::Vector2f(200, 450));
			waypoints->push_back(sf::Vector2f(650, 450));
			waypoints->push_back(sf::Vector2f(650, 350));
			waypoints->push_back(sf::Vector2f(680, 350));
			waypoints->push_back(sf::Vector2f(760, 350));
		}
		else if (firstPath == 2 && secondPath == 2)
		{
			waypoints->push_back(sf::Vector2f(125, 275));
			waypoints->push_back(sf::Vector2f(125, 350));
			waypoints->push_back(sf::Vector2f(200, 350));
			waypoints->push_back(sf::Vector2f(200, 400));
			waypoints->push_back(sf::Vector2f(200, 450));
			waypoints->push_back(sf::Vector2f(650, 450));
			waypoints->push_back(sf::Vector2f(650, 350));
			waypoints->push_back(sf::Vector2f(680, 350));
			waypoints->push_back(sf::Vector2f(760, 350));
			waypoints->push_back(sf::Vector2f(760, 275));
			waypoints->push_back(sf::Vector2f(810, 275));
		}

	}
	return waypoints;
}