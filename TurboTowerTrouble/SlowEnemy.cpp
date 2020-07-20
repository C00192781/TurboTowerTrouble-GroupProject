#include "SlowEnemy.h"

SlowEnemy::SlowEnemy()
{

}

SlowEnemy::SlowEnemy(sf::Texture &texture)
{
	m_sprite.setTexture(texture);
	m_health = 100;
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
// \brief Update method for this particular enemy. It will 
//		  move slowly, and its healthbar will change based 
//		  on the current health.
// Contributors: Simon Dowling
//
// Notes: Get first waypoint -> go to it.
//		  Once we're at the current waypoint, find the next one.
////////////////////////////////////////////////////////////
void SlowEnemy::update()
{
	m_healthBar.setSize(sf::Vector2f(m_health, 2));
	m_position=m_enemyAI.update(m_position);
	m_sprite.setPosition(m_position);
	m_healthBar.setPosition(sf::Vector2f(m_position.x - 30, m_position.y + 20));
}

////////////////////////////////////////////////////////////
// \brief Draw method for this enemy.
// Will probably incorporate a pointer to a shader later.
// Contributors: Simon Dowling
//
////////////////////////////////////////////////////////////
void SlowEnemy::draw(sf::RenderWindow *window)
{
	window->draw(m_sprite);
	window->draw(m_healthBar);
}

sf::Vector2f SlowEnemy::getPosition()
{
	return m_position;
}

int SlowEnemy::getHealth()
{
	return m_health;
}
std::shared_ptr<sf::Sprite> SlowEnemy::getEnemySprite()
{
	std::shared_ptr<sf::Sprite>temp;
	temp = std::make_shared<sf::Sprite>(m_sprite);
	return temp;
}

std::shared_ptr<int> SlowEnemy::getHealthPointer()
{
	std::shared_ptr<int>temp;
	temp = std::make_shared<int>(m_health);
	return temp;
}