#include "BaseTower.h"

BaseTower::BaseTower()
{

}

BaseTower::BaseTower(sf::Texture &texture) : m_fireCounter(0)  //, fireRate(10)
{
	type = TowerType::Vanilla;
	if (type == TowerType::Vanilla)
	{
		m_range = 100;
		m_fireRate = 40;
		m_damage = 20;
		//rotateSpeed = 10000;
	}
	towerFire.loadFromFile(".\\Sound Effects\\towerShooting.wav");
	sound.setBuffer(towerFire);
	m_sprite.setTexture(texture);
	rotateToPoint.first = 0;
	rotateToPoint.second = true;
	// rotateSpeed =0;
	setRange(m_range);
	//m_range = 50;
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	m_sprite.setScale(0.7, 0.7);
	m_maxProjectiles = 20;
	m_fireIndex = 0;
	texture.setSmooth(true);
	//projectilesVector.reserve(100);
}
void BaseTower::update()
{
	for (int i = 0; i < projectilesVector.size(); i++)
	{
		projectilesVector[i].update();
		if (true == projectilesVector[i].checkBoundaries())
		{
			projectilesVector.erase(projectilesVector.begin() + i);
		}
		//std::cout << m_fireIndex << std::endl;
	}
}

void BaseTower::requestFire(sf::Vector2f enemyPos)
{
	sound.setBuffer(towerFire);
	if (m_fireCounter > m_fireRate)
	{
		projectilesVector.push_back(Projectiles(m_sprite.getPosition()));
		projectilesVector[projectilesVector.size() - 1].calculateDirectionVector(enemyPos);
		m_fireCounter = 0;
		projectiles[projectilesVector.size() - 1].isFired = true;
		//projectiles[m_fireIndex].calculated = false;
		//sound.setPosition(sf::Vector3f(m_sprite.getPosition().x, m_sprite.getPosition().y, 15));
		
		sound.play();
		//fireBullet(m_fireIndex);



		//if (m_fireIndex < m_maxProjectiles)
		//{
		//	if (m_fireIndex < 20)
		//	{
		//		m_fireIndex++;
		//	}
		//	else
		//	{
		//		m_fireIndex = 0;
		//	}//= (m_fireIndex + 1) % 20;
		//}

	}
	else
	{
		m_fireCounter++;
	}
	//std::cout << m_fireIndex << "" << std::endl;

}

void BaseTower::setTowerRotationAngle(sf::Vector2f enemyPos)
{
	sf::Vector2f pos(enemyPos.y - m_sprite.getPosition().y, enemyPos.x - m_sprite.getPosition().x);
	const float PI = 3.14159;
	float rotationDeg = atan2(-1 * pos.y, pos.x) / PI * 180 + 180;
	rotateToPoint.first = std::round(rotationDeg);
	rotateToPoint.second = false;
}

bool BaseTower::rotateTower()
{
	alligned = false; //if we go into this method, we're not facing the enemy
	int degrees = m_sprite.getRotation(); //get sprites angle
	if (degrees != rotateToPoint.first) //if the sprite is not facing the enemyPos
	{
		alligned = false; //we're not alligned
		int rotation = rotateToPoint.first - degrees; //rotation = rotationDeg - degrees.
		int signOfRotation = std::copysign(1.0f, rotation); //get direction to rotate
		int rotationSpeedDegrees = 1; //how fast the tower will rotate;

		if (std::abs(rotation) <= rotationSpeedDegrees)
		{
			m_sprite.rotate(signOfRotation * rotationSpeedDegrees);
		}

		if (std::abs(rotation) < 180)
		{
			m_sprite.rotate(signOfRotation * rotationSpeedDegrees);
		}

		else
		{
			m_sprite.rotate(-1.0f * signOfRotation * rotationSpeedDegrees);
		}

		if (std::abs(rotation) <= rotationSpeedDegrees + 2 && std::abs(rotation) >= rotationSpeedDegrees - 2)
		{
			alligned = true;
		}
	}
	return alligned;
}

void BaseTower::draw(sf::RenderWindow *window)
{

	for (int i = 0; i < projectilesVector.size(); i++)
	{
		projectilesVector[i].projectileSprite.setTexture(projectilesVector[i].m_projectileTexture);
		projectilesVector[i].Draw(window);
	}
	window->draw(m_sprite);
}

void BaseTower::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);

}

sf::Sprite BaseTower::getSprite()
{
	return m_sprite;
}

void BaseTower::setRange(float range)
{
	m_range = range;
	m_circle = sf::CircleShape(range);
	m_circle.setFillColor(sf::Color::Transparent);
	m_circle.setOutlineThickness(2);
	m_circle.setOutlineColor(sf::Color(255, 0, 0, 128));
	m_circle.setOrigin(range, range);
	m_circle.setPosition(m_sprite.getPosition());
}

sf::CircleShape BaseTower::getRangeIndicator()
{
	return m_circle;
}

BaseTower::~BaseTower()
{
}

bool BaseTower::checkEnemyInRange(sf::Vector2f enemyPos)
{
	bool inRange = false;
	if (m_circle.getGlobalBounds().contains(enemyPos))
	{
		inRange = true;
	}
	return inRange;
}

void BaseTower::targetEnemy(sf::Vector2f enemyPos)
{
	setTowerRotationAngle(enemyPos);
	if (rotateToPoint.second == false)
	{
		rotateToPoint.second = rotateTower();
		if (alligned == true)
		{
			requestFire(enemyPos);
		}

	}
}

void BaseTower::setProjectilePosition(sf::Vector2f projectilePos)
{
	for (int i = 0; i < projectilesVector.size(); i++)
	{
		projectilesVector[i].setProjectilePosition(projectilePos);
	}
}

void BaseTower::fireBullet(int &index)
{
	m_fireCounter = 0;
	projectiles[index].isFired = true;
	projectiles[index].calculated = false;

	//std::cout << index << std::endl;

	if (index >= 19)
	{
		index = 0;
	}
	index++;
	//projectiles[m_fireIndex].isFired = true;
	//projectiles[m_fireIndex].calculated = false;

	//std::cout << m_fireIndex << std::endl;
	//m_fireIndex++;
	//if (m_fireIndex > 19)
	//{
	//	m_fireIndex = 0;
	//}

}


int BaseTower::checkCollision(std::shared_ptr<sf::Sprite> enemySprite, std::shared_ptr<int> health) // , int size
{
	for (int j = 0; j < projectilesVector.size(); j++)
	{
		if (enemySprite->getGlobalBounds().intersects(projectilesVector[j].projectileSprite.getGlobalBounds()))
		{
			projectilesVector.erase(projectilesVector.begin() + j);
			*health = *health - m_damage;
		}
	}
	return *health;
}


void BaseTower::TowerBaseUpgrade(TowerType towerType, sf::Texture &texture)
{
	m_sprite.setTexture(texture);
	type = towerType;
	if (type == TowerType::SniperTurret)
	{
		m_range = 500;
		m_fireRate = 60;
		m_damage = 60;
		//m_sprite.setTexture(sniperTexture);

	}
	if (type == TowerType::UziTurret)
	{
		m_range = 150;
		m_fireRate = 5;
		m_damage = 15;
		//m_sprite.setTexture(uziTexture);
	}
	setRange(m_range);
}

//void BaseTower::checkCollision(std::shared_ptr<sf::Sprite> enemySprite, std::shared_ptr<int> health) // , int size
//{
//	for (int j = 0; j < m_maxProjectiles; j++)
//	{
//		if (enemySprite->getGlobalBounds().intersects(projectiles[j].projectileSprite.getGlobalBounds()))
//		{
//			projectiles[j].resetProjectilePosition();
//			*health = *health - 10;
//		}
//	}
//}

