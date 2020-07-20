#include "WavePhase.h"
#include "Paths.h"
#include <iostream>



WavePhase::WavePhase()
{
	
}

WavePhase::WavePhase(std::shared_ptr<int> mapCount)
{
	enemyCount = 10;
	slowEnemyTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
	fastEnemyTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
	mediumEnemyTexture = std::shared_ptr<sf::Texture>(new sf::Texture());
	if (!slowEnemyTexture->loadFromFile("Sprites Folder/Enemy Sprites/Scrub1.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!fastEnemyTexture->loadFromFile("Sprites Folder/Enemy Sprites/Scrub2.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!mediumEnemyTexture->loadFromFile("Sprites Folder/Enemy Sprites/Scrub3.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!baseTexture.loadFromFile("Sprites Folder/baseSprite.png"))
	{
		std::cout << "Error" << std::endl;
	}
	baseTexture.setSmooth(true);
	slowEnemyTexture->setSmooth(true);
	fastEnemyTexture->setSmooth(true);
	mediumEnemyTexture->setSmooth(true);
	spawnTimer = 0;
	m_base = PlayerStronghold(sf::Vector2f(800, 260), sf::Vector2f(740, 230), 100, baseTexture);
	m_map = mapCount;
	waveState = 0;
	wave = 0;
	if (*m_map == 2)
	{
		//m_base.setPosition(sf::Vector2f(790, 240), sf::Vector2f(790, 240));
	}
}
void WavePhase::CheckBaseCollision()
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		if (m_base.getSprite().getGlobalBounds().intersects(m_enemies.at(i).getEnemySprite()->getGlobalBounds()))
		{
			m_base.TakeDamage();
			std::cout << m_base.getHealth() << std::endl;
			m_enemies.erase(m_enemies.begin() + i);
		}
	}
}

void WavePhase::Draw(sf::RenderWindow *window, sf::Shader *shader, std::shared_ptr<std::vector<BaseTower>> towers)
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies.at(i).draw(window);
	}
	for (int i = 0; i < towers->size(); i++)
	{
		towers->at(i).draw(window);
	}
	m_base.Draw(window);
}

void WavePhase::Update(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency, std::shared_ptr<int> score, bool *pGameOver)
{
	//testEnemy.update();
	//std::cout << testEnemy.getPosition().x << std::endl;
	//std::cout << testEnemy.getPosition().y << std::endl;

	for (int i = 0; i < towers->size(); i++)
	{
		towers->at(i).update();
		for (int e = 0; e < m_enemies.size(); e++)
		{
			//m_enemies.at(i).setHealth(towers->at(i).checkCollision(m_enemies.at(i).getEnemySprite(), m_enemies.at(i).getHealthPointer())); // , m_slowEnemies.size()
			m_enemies.at(e).setHealth(towers->at(i).checkCollision(m_enemies.at(e).getEnemySprite(), m_enemies.at(e).getHealthPointer()));
		}
	}
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies.at(i).update();
		if (m_enemies.at(i).getHealth() < 0)
		{
			m_enemies.erase(m_enemies.begin() + i);
			*currency = *currency + 2;
			*score = *score + 10;
		}
	}
	if (m_base.getHealth() <= 0)
	{
		*pGameOver = true;
	}
	TowerTargeting(towers);
	Waves();
	CheckBaseCollision();
}

int  WavePhase::getTowerHealth()
{
	return m_base.getHealth();
}
void WavePhase::TowerTargeting(std::shared_ptr<std::vector<BaseTower>> towers)
{

	for (int t = 0; t < towers->size(); t++)
	{
		int weakestHealthSlow = 101;
		int weakestIndexSlow;
		bool slowEnemyInRadius = false;
		int weakestHealthFast = 40 + 1;
		int weakestIndexFast;
		bool fastEnemyInRadius = false;
		int weakestHealthMedium = 75 + 1;
		int weakestIndexMedium;
		bool mediumEnemyInRadius = false;
		for (int s = m_enemies.size() - 1; s > -1; s--)
		{
			if (true == towers->at(t).checkEnemyInRange(m_enemies.at(s).getPosition()))
			{
				if (m_enemies.at(s).type == BaseEnemy::EnemyType::Slow)
				{
					slowEnemyInRadius = true;
					if (m_enemies.at(s).getHealth() <= weakestHealthSlow)
					{
						weakestHealthSlow = m_enemies.at(s).getHealth();
						weakestIndexSlow = s;

					}
				}
				else if (m_enemies.at(s).type == BaseEnemy::EnemyType::Fast)
				{
					fastEnemyInRadius = true;
					if (m_enemies.at(s).getHealth() <= weakestHealthFast)
					{
						weakestHealthFast = m_enemies.at(s).getHealth();
						weakestIndexFast = s;

					}
				}
				else
				{
					mediumEnemyInRadius = true;
					if (m_enemies.at(s).getHealth() <= weakestHealthMedium)
					{
						weakestHealthMedium = m_enemies.at(s).getHealth();
						weakestIndexMedium = s;

					}
				}
			}

		}

		if (slowEnemyInRadius == true)
		{
			if (mediumEnemyInRadius == true && fastEnemyInRadius == false)
			{
				if (comparePercentageHealth(weakestIndexMedium, 75, weakestIndexSlow, 100) == true)
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexMedium).getPosition());
				}
				else
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexSlow).getPosition());
				}
			}
			else if (mediumEnemyInRadius == false && fastEnemyInRadius == true)
			{
				if (comparePercentageHealth(weakestIndexFast, 40, weakestIndexSlow, 100) == true)
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexFast).getPosition());
				}
				else
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexSlow).getPosition());
				}
			}
			else if (mediumEnemyInRadius == false && fastEnemyInRadius == false)
			{
				towers->at(t).targetEnemy(m_enemies.at(weakestIndexSlow).getPosition());
			}
			else
			{
				if (comparePercentageHealth(weakestIndexFast, 40, weakestIndexSlow, 100) == true)
				{
					if (comparePercentageHealth(weakestIndexFast, 40, weakestIndexMedium, 75) == true)
					{
						towers->at(t).targetEnemy(m_enemies.at(weakestIndexFast).getPosition());
					}
					else
					{
						towers->at(t).targetEnemy(m_enemies.at(weakestIndexMedium).getPosition());
					}
				}
				else
				{
					if (comparePercentageHealth(weakestIndexSlow, 40, weakestIndexMedium, 75) == true)
					{
						towers->at(t).targetEnemy(m_enemies.at(weakestIndexSlow).getPosition());
					}
					else
					{
						towers->at(t).targetEnemy(m_enemies.at(weakestIndexMedium).getPosition());
					}
				}
			}
		}
		else if (mediumEnemyInRadius == true)
		{

			if (fastEnemyInRadius == true)
			{
				if (comparePercentageHealth(weakestIndexMedium, 75, weakestIndexFast, 40) == true)
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexMedium).getPosition());
				}
				else
				{
					towers->at(t).targetEnemy(m_enemies.at(weakestIndexFast).getPosition());
				}
			}
			else
			{
				towers->at(t).targetEnemy(m_enemies.at(weakestIndexMedium).getPosition());
			}

		}
		else if (fastEnemyInRadius == true)
		{
			towers->at(t).targetEnemy(m_enemies.at(weakestIndexFast).getPosition());
		}
		else
		{

		}
	}

}


void WavePhase::Waves()
{
	if (spawnTimer > 100)
	{
		bool spawned = false;
		if (*m_map == 2)
		{
			if (wave == 0)
			{
				enemyCount = 20;
				wave = 1;
			}
			if (wave == 1)
			{
				if (enemyCount > 0 && spawned == false)
				{
					EnemySpawns();
					enemyCount--;
					spawned = true;
				}
				if (enemyCount == 0 && m_enemies.size() == 0)
				{
					wave = 2;
					enemyCount = 20;
					waveState = 1;//Build Phase
				}
			}
			if (wave == 2)
			{
				if (enemyCount > 0 && spawned == false)
				{
					EnemySpawns();
					enemyCount--;
					spawned = true;
				}
				if (enemyCount == 0 && m_enemies.size() == 0)
				{
					wave = 0;
					waveState = 2;//Next Map
					*m_map = 3;
				}
			}
		}


		if (*m_map == 3)
		{
			if (wave == 0)
			{
				enemyCount = 20;
				wave = 1;
			}
			if (wave == 1)
			{
				if (enemyCount > 0 && spawned == false)
				{
					EnemySpawns();
					enemyCount--;
					spawned = true;
				}
				if (enemyCount == 0 && m_enemies.size() == 0)
				{
					wave = 2;
					enemyCount = 20;
					waveState = 1;//Build Phase
				}
			}
			if (wave == 2)
			{
				if (enemyCount > 0 && spawned == false)
				{
					EnemySpawns();
					enemyCount--;
					spawned = true;
				}
				if (enemyCount == 0 && m_enemies.size() == 0)
				{
					wave = 0;
					waveState = 3;//Next Map
				}
			}
		}
		spawnTimer = 0;
	}
	spawnTimer++;
}


bool WavePhase::comparePercentageHealth(int indexOne, int maxHealthOne, int indexTwo, int maxHealthTwo)
{
	bool firstIsSmaller;
	if (m_enemies.at(indexOne).getHealth() / maxHealthOne < m_enemies.at(indexTwo).getHealth() / maxHealthTwo)
	{
		firstIsSmaller = true;
	}
	else
	{
		firstIsSmaller = false;
	}
	return firstIsSmaller;
}

int WavePhase::getWaveState()
{
	return waveState;
}

void WavePhase::EnemySpawns()
{
	if (enemyCount > 18)
	{
		m_enemies.push_back(BaseEnemy(slowEnemyTexture, BaseEnemy::EnemyType::Slow, Paths::getPath(*m_map, 1, 1)));
	}
	if (enemyCount < 19 && enemyCount >14)
	{
		m_enemies.push_back(BaseEnemy(fastEnemyTexture, BaseEnemy::EnemyType::Fast, Paths::getPath(*m_map, 1, 2)));
	}
	if (enemyCount < 15 && enemyCount > 10)
	{
		m_enemies.push_back(BaseEnemy(mediumEnemyTexture, BaseEnemy::EnemyType::Medium, Paths::getPath(*m_map, 2, 1)));
	}
	if (enemyCount < 11 && enemyCount > 6)
	{
		m_enemies.push_back(BaseEnemy(slowEnemyTexture, BaseEnemy::EnemyType::Slow, Paths::getPath(*m_map, 2, 2)));
	}
	if (enemyCount < 7 && enemyCount > 3)
	{
		m_enemies.push_back(BaseEnemy(fastEnemyTexture, BaseEnemy::EnemyType::Fast, Paths::getPath(*m_map, 1, 2)));
	}
	if (enemyCount < 4 && enemyCount > 0)
	{
		m_enemies.push_back(BaseEnemy(mediumEnemyTexture, BaseEnemy::EnemyType::Medium, Paths::getPath(*m_map, 2, 1)));
	}
}
