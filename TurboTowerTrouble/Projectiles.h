////////////////////////////////////////////////////////////
/// Names: Kevin Boylan, Simon Dowling, Matthew Watson
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief This class will be used to get the tower to fire projectiles
/// \param The bullet will go towards/target the enemy (if the are within range)
///        Currently, the range and and other elements are not yet in place
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <list>


class Projectiles
{
public:
	Projectiles();
	Projectiles(sf::Vector2f towerPosition);
	void update();
	void resetProjectilePosition();
	void Draw(sf::RenderWindow *window);
	sf::Vector2f position;
	sf::Vector2f velocity;
	int m_maxBullets;
	int m_TimeAlive;
	bool calculated;
	bool isFired;
	bool outOfBounds;
	std::vector<sf::Vector2f> m_position;
	int m_shootingPoints[10];

	std::vector<sf::Vector2f> m_DirectionVector;
	void calculateDirectionVector(sf::Vector2f enemyPos);
	sf::Sprite projectileSprite;
	int index;
	sf::Texture m_projectileTexture;
	sf::Vector2f firePoint;
	sf::Vector2f diff;
	float m_velocity;
	void setProjectilePosition(sf::Vector2f pos);

	sf::Vector2f posHolder;
	bool checkBoundaries();
private:
	sf::Clock m_clock;
	void create();

	sf::Vector2f normalize(sf::Vector2f v);
};