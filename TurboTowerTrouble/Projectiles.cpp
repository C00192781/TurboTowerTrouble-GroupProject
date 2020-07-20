////////////////////////////////////////////////////////////
/// Names: Kevin Boylan, 
///		   Simon Dowling
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief This class will be used to get the tower to fire projectiles
/// \param The bullet will go towards/target the enemy (if the are within range)
///        Currently, the range and and other elements are not yet in place
////////////////////////////////////////////////////////////

#include "Projectiles.h"
#include <iostream>
#include <memory>
//#include "stdafx.h"


////////////////////////////////////////////////////////////
/// \brief This is the constructor, and it assigns variables and sets up the sprite
/// \param Once the texture is loaded, it is set, the position is set and the scale is set
////////////////////////////////////////////////////////////

Projectiles::Projectiles()
{

}

Projectiles::Projectiles(sf::Vector2f towerPosition)
{

	m_maxBullets = 10;
	if (!m_projectileTexture.loadFromFile("Sprites Folder/bullet.png"))
	{

	}
	
	position = towerPosition;
	projectileSprite.setTexture(m_projectileTexture);
	projectileSprite.setPosition(position.x, position.y);
	projectileSprite.setScale(0.25f, 0.25f);
	m_velocity = -5.0f;
	calculated = false;
	isFired = false;
}

////////////////////////////////////////////////////////////
/// \brief This is the update method, and it will be used to keep methods and variables updating
/// \param	Update will do this when it is called in another class
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
/// \brief This is the create method, and it will be used to create sprites (possibly)
/// \param	
////////////////////////////////////////////////////////////
void Projectiles::create()
{

}

//void Projectiles::calculateDirectionVector(sf::Vector2f enemyPos, sf::Vector2f pos)

////////////////////////////////////////////////////////////
/// \brief This method will be used to calculate where the bullet must go to hit the enemy
/// \param	Variables such as the enemy position are passed in, and the calculations are performed
////////////////////////////////////////////////////////////


sf::Vector2f Projectiles::normalize(sf::Vector2f v)
{
	float length = sqrt((v.x * v.x) + (v.y * v.y));
	return sf::Vector2f(v.x / length, v.y / length);
}

void Projectiles::setProjectilePosition(sf::Vector2f pos)
{
	position.x = pos.x;
	position.y = pos.y;
}
void Projectiles::calculateDirectionVector(sf::Vector2f enemyPos)
{
	diff.x = position.x - enemyPos.x;
	diff.y = position.y - enemyPos.y;

	diff.x += m_velocity;
	diff.y += m_velocity;

	diff = normalize(diff);
	calculated = true;
}


void Projectiles::update()
{
		position.x += diff.x * m_velocity;
		position.y += diff.y * m_velocity;
		projectileSprite.setPosition(position.x, position.y);
	
	checkBoundaries();
}




////////////////////////////////////////////////////////////
/// \brief This is the draw method, and it will draw the arraw of sprites
/// \param	if the sprite fits within the index, it will draw
////////////////////////////////////////////////////////////
void Projectiles::Draw(sf::RenderWindow *window)
{
		window->draw(projectileSprite);
}

bool Projectiles::checkBoundaries()
{
	bool collision= false;
		if (position.x < 0 || position.x > 1080 || position.y < 0 || position.y > 1080)
		{
			collision = true;
			
		}
		return collision;
}

void Projectiles::resetProjectilePosition()
{
	position.x = posHolder.x;
	position.y = posHolder.y;
	projectileSprite.setPosition(position.x, position.y);
	isFired = false;
	calculated = false;
}