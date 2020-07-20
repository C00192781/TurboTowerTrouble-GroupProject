////////////////////////////////////////////////////////////
// BaseEnemy class for others to inherit from.
// Contributors: Simon Dowling, Kevin Boylan, Matthew Watson
//
////////////////////////////////////////////////////////////
#include "BaseEnemy.h"

BaseEnemy::BaseEnemy()
{

}
////////////////////////////////////////////////////////////
/// \brief Default constructor
///
////////////////////////////////////////////////////////////
BaseEnemy::BaseEnemy(std::shared_ptr<sf::Texture> texture, EnemyType enemytype, std::shared_ptr<std::vector<sf::Vector2f>> waypoints)
{
	m_enemyAI = EnemyAI(waypoints);
	m_sprite.setTexture(*texture);
	type = enemytype;
	if (type == EnemyType::Fast)
	{
		m_health = 40;
		m_enemyAI.m_speed = 1.25;
	}
	if (type == EnemyType::Medium)
	{
		m_health = 75;
		m_enemyAI.m_speed = 1;
	}
	if (type == EnemyType::Slow)
	{
		m_health = 100;
		m_enemyAI.m_speed = 0.5;
	}
	m_position = sf::Vector2f(30, 280);
	pPosition = std::make_shared<sf::Vector2f>(m_position);
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(90);
	m_sprite.setScale(0.5, 0.5);
	m_healthBar.setSize(sf::Vector2f(m_health, 2));
	m_healthBar.setScale(0.2, 1.0);
	m_healthBar.setPosition(sf::Vector2f(m_position.x - 30, m_position.y + 20));
	m_healthBar.setFillColor(sf::Color::Green);
}
////////////////////////////////////////////////////////////
/// \brief Update method that will be inherited by all enemy types.
///
////////////////////////////////////////////////////////////
void BaseEnemy::update()
{
	m_healthBar.setSize(sf::Vector2f(m_health, 2));
	m_position = m_enemyAI.update(m_position);
	m_sprite.setPosition(m_position);
	m_healthBar.setPosition(sf::Vector2f(m_position.x - 30, m_position.y + 20));
}
////////////////////////////////////////////////////////////
/// \brief Method to resolve the collisions based on what projectile is received.
///
////////////////////////////////////////////////////////////
void BaseEnemy::resolveCollisions()
{

}

void BaseEnemy::draw(sf::RenderWindow *window)
{
	window->draw(m_sprite);
	window->draw(m_healthBar);
}

BaseEnemy::~BaseEnemy()
{
}

sf::Vector2f BaseEnemy::getPosition()
{
	return m_position;
}

int BaseEnemy::getHealth()
{
	return m_health;
}
std::shared_ptr<sf::Sprite> BaseEnemy::getEnemySprite()
{
	std::shared_ptr<sf::Sprite>temp;
	temp = std::make_shared<sf::Sprite>(m_sprite);
	return temp;
}

std::shared_ptr<int> BaseEnemy::getHealthPointer()
{
	std::shared_ptr<int>temp;
	temp = std::make_shared<int>(m_health);
	return temp;
}
void BaseEnemy::setHealth(int health)
{
	m_health = health;
}
