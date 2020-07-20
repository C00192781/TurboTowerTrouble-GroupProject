#include "TowerGraphics.h"


TowerGraphics::TowerGraphics()
{
	m_Texture.loadFromFile("Dizzy.png");
	m_Sprite.setTexture(m_Texture);
	rotateToPoint.first = 0;
	rotateToPoint.second = true;
}


TowerGraphics::~TowerGraphics()
{
}
void TowerGraphics::update()
{
	//if (enemy is inside our range)
	//{
	//	setTowerRotationAngle(sf::Vector2f enemyPos, sf::Sprite & sprite)
	//}
	//if (rotateToPoint.second == false)
	//{
	//	rotateToPoint.second = rotateTower(m_Sprite)
	//}
	//if (rotateToPoint.second == true)
	//{
	//  //Shoot at the enemy
	//}
}

void TowerGraphics::setTowerRotationAngle(sf::Vector2f enemyPos) //Simon
{
	sf::Vector2f pos(enemyPos.y - m_Sprite.getPosition().y, enemyPos.x - m_Sprite.getPosition().x);
	const float PI = 3.14159;
	float rotationDeg = atan2(-1 * pos.y, pos.x) / PI * 180 + 180; 
	rotateToPoint.first = std::round(rotationDeg);
	rotateToPoint.second = false;
}

bool TowerGraphics::rotateTower()
{
	bool alligned = false; //if we go into this method, we're not facing the enemy
	int degrees = m_Sprite.getRotation(); //get sprites angle
	if (degrees != rotateToPoint.first) //if the sprite is not facing the enemyPos
	{
		alligned = false; //we're not alligned
		int rotation = rotateToPoint.first - degrees; //rotation = rotationDeg - degrees.
		int signOfRotation = std::copysign(1.0f, rotation); //get direction to rotate
		int rotationSpeedDegrees = 3; //how fast the tower will rotate;
		
		if (std::abs(rotation) <= rotationSpeedDegrees)
		{
			m_Sprite.rotate(signOfRotation * rotationSpeedDegrees);
		}
		
		if (std::abs(rotation) < 180)
		{
			m_Sprite.rotate(signOfRotation * rotationSpeedDegrees);
		}
		
		else
		{
			m_Sprite.rotate(-1.0f * signOfRotation * rotationSpeedDegrees);
		}
	}
	return alligned;
}