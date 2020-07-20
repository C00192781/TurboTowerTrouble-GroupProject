
////////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Matthew Watson, Kevin Boylan, Simon Dowling,  Rolands Stafeckis
////////////////////////////////////////////////////////////
#include "SFML/Graphics.hpp" 
#include "Grid.h"
#include "BaseTower.h"
#include <memory.h>

class BuildPhase
{
public:
	BuildPhase();
	BuildPhase(std::shared_ptr<Grid> theGrid, sf::Texture &vanillaTexture, sf::Texture &sniperTexture, sf::Texture &uziTexture);
	void Draw(sf::RenderWindow *window, sf::Shader *shader, std::shared_ptr<std::vector<BaseTower>> towers);
	void Update(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency);
	bool getStartWave();
	void setStartWave(bool startWave);
	void setTowerBases(std::shared_ptr<Grid> theGrid);
private:
	bool m_startWave;
	//////////////////
	// \brief uses controller to cycle through towers and selects them
	////////
	void TowerSelection();
	void checkContinueToWave();
	////////////////////
	// \brief uses controller input, checks which tower to upgrade and what to upgrade to
	///////////////////
	void buildTower(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency);
	unsigned int countSincePressed;
	unsigned int buttonPressDelay = 10;
	unsigned int currentTowerBase;
	sf::Texture vanillaTex;
	sf::Texture sniperTex;
	sf::Texture uziTex;
	std::vector<TowerBase> m_towerBases;

	void upgrade(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency);
};