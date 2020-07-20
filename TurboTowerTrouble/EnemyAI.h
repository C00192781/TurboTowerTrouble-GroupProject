/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Kevin Boylan, Matthew Watson
////////////////////////////////////////////////////////////

#include "SFML/Graphics.hpp"
#include <string>
#include <memory>


////////////////////////////////////////////////////////////
/// \brief A  class that handles the Enemy AI, 
///  for the paths it follows (waypoints).
////////////////////////////////////////////////////////////
class EnemyAI
{

public:
	EnemyAI();
	EnemyAI(std::shared_ptr<std::vector<sf::Vector2f>> waypoints);

	void initialize();
	sf::Vector2f update(sf::Vector2f enemyPos);

	float m_speed;
	// A set of waypoints for this AI path.
	std::shared_ptr<std::vector<sf::Vector2f>> m_wayPoints;
private:
	int index;
	bool xPath;
	bool yPath;

};