#include "BuildPhase.h"

BuildPhase::BuildPhase()
{

}

BuildPhase::BuildPhase(std::shared_ptr<Grid> theGrid, sf::Texture &vanillaTexture, sf::Texture &sniperTexture, sf::Texture &uziTexture)
{
	theGrid->SetTowerBases(m_towerBases);
	currentTowerBase = 0;
	countSincePressed = 0;
	m_startWave = false;
	vanillaTex = vanillaTexture;
	sniperTex = sniperTexture;
	uziTex = uziTexture;
}

void BuildPhase::Update(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency)
{
	sf::Joystick::update();//LB=4 RB=5
	TowerSelection();
	checkContinueToWave();
	buildTower(towers,currency);
	upgrade(towers,currency);
}

void BuildPhase::Draw(sf::RenderWindow *window, sf::Shader *shader, std::shared_ptr<std::vector<BaseTower>> towers)
{
	for (int i = 0; i < m_towerBases.size(); i++)
	{
		m_towerBases.at(i).Draw(window);

	}
	for (int i = 0; i < towers->size(); i++)
	{
		towers->at(i).draw(window);
		if (m_towerBases.at(towers->at(i).towerBaseIndex).selected == true)
		{
			window->draw(towers->at(i).getRangeIndicator());
		}
	}
}

void BuildPhase::TowerSelection()
{

	if ((sf::Joystick::isButtonPressed(0, 4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && countSincePressed > buttonPressDelay)
	{
		m_towerBases[currentTowerBase].SetSelected(false);
		if (currentTowerBase < m_towerBases.size()-1)
		{
			currentTowerBase++;
		}
		else
		{
			currentTowerBase = 0;
		}
		m_towerBases[currentTowerBase].SetSelected(true);
		countSincePressed = 0;
	}
	if ((sf::Joystick::isButtonPressed(0, 5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && countSincePressed > buttonPressDelay)
	{
		m_towerBases[currentTowerBase].SetSelected(false);
		if (currentTowerBase > 0)
		{
			currentTowerBase--;
		}
		else
		{
			currentTowerBase = m_towerBases.size()-1;
		}
		m_towerBases[currentTowerBase].SetSelected(true);
		countSincePressed = 0;
	}
	else
	{
		countSincePressed++;
	}
}


void BuildPhase::buildTower(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency)
{
	if (sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int index = 0; index < m_towerBases.size(); index++)
		{
			if (m_towerBases.at(index).hasTower == false)
			{
				if (m_towerBases.at(index).selected == true)
				{
					towers->push_back(BaseTower(vanillaTex));
					towers->at(towers->size() - 1).setPosition(sf::Vector2f(m_towerBases.at(index).getPosition().x + towers->at(towers->size() - 1).getSprite().getGlobalBounds().width / 2 + 4,
																              m_towerBases.at(index).getPosition().y + towers->at(towers->size() - 1).getSprite().getGlobalBounds().height / 2)); //place the tower in the right place.
					towers->at(towers->size() - 1).setRange(100);
					towers->at(towers->size() - 1).towerBaseIndex = index;
					m_towerBases.at(index).hasTower = true;
					//substract money
					//adjust ui
				}
			}

			else if (m_towerBases.at(index).hasTower == true)
			{
				//upgrade UI
				//sell UI
			}
		}
	}
}

void BuildPhase::setStartWave(bool startWave)
{
	m_startWave = startWave;
}

bool BuildPhase::getStartWave()
{
	return m_startWave;
}

void BuildPhase::checkContinueToWave()
{
	if (sf::Joystick::isButtonPressed(0, 1) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_startWave = true;
	}
}

void BuildPhase::upgrade(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency)
{
	if (*currency >=20)
	{
		if (sf::Joystick::isButtonPressed(0, 2) || sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			for (int index = 0; index < m_towerBases.size(); index++)
			{
				if (m_towerBases.at(index).hasTower == true)
				{
					if (m_towerBases.at(index).selected == true)
					{
						for (int i = 0; i < towers->size(); i++)
						{
							if (towers->at(i).towerBaseIndex == index)
							{
								if (BaseTower::TowerType::UziTurret != towers->at(i).type)
								{
									*currency = *currency - 20;
								}
								towers->at(i).TowerBaseUpgrade(BaseTower::TowerType::UziTurret, uziTex);
							}
						}
					}
				}
			}
		}

		if (sf::Joystick::isButtonPressed(0, 3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			for (int index = 0; index < m_towerBases.size(); index++)
			{
				if (m_towerBases.at(index).hasTower == true)
				{
					if (m_towerBases.at(index).selected == true)
					{
						for (int i = 0; i < towers->size(); i++)
						{
							if (towers->at(i).towerBaseIndex == index)
							{
								if (BaseTower::TowerType::SniperTurret != towers->at(i).type)
								{
									*currency = *currency - 20;
								}
								towers->at(i).TowerBaseUpgrade(BaseTower::TowerType::SniperTurret, sniperTex);
							}
						}
					}
				}
			}
		}
	}
}

void BuildPhase::setTowerBases(std::shared_ptr<Grid> theGrid)
{
	m_towerBases.clear();
	m_towerBases.shrink_to_fit();
	theGrid->SetTowerBases(m_towerBases);
}