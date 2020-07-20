////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// \brief Class to manage whether it is the build phase or wave phase
///  //Contributers : Matthew Watson, Dermot Mac Conville, Kevin Boylan
////////////////////////////////////////////////////////////////////////

#include "SFML\Graphics.hpp"
#include "BuildPhase.h"
#include "WavePhase.h"
#include "BaseTower.h"
#include "Light.h"
#include "MainMenu.h"
#include "PlayerStronghold.h"
#include <memory>
#include "ParticleFarm.h"
#include "Hud.h"
#include "GameOverScreen.h"
#include <iostream>

class GamesPhaseManager
{
private:
	GameOverScreen scr;
	bool gameOver;
	bool *pGameOver;
	BuildPhase m_BuildPhase;
	WavePhase m_WavePhase;
	Grid testGrid;
	std::vector<BaseTower> m_towers;
	sf::Texture enemyTex;
	sf::Texture enemyTex2;
	sf::Texture enemyTex3;
	sf::Texture uziTexture;
	sf::Texture vanillaTexture;
	sf::Texture sniperTexture;
	ParticleFarm tokenParticles;
	std::shared_ptr<int> pCurrency;
	int m_currency;
	std::shared_ptr<int> pScore;
	int m_score;
	Hud gameHud;
	enum class GamePhase
	{
		Build,
		Wave,
		Pause,
		MainMenu,
		GameOver,
		Exit
	};
	MainMenu m_menu;
	MainMenu  m_pauseMenu;
	GamePhase theGamePhase;
	GamePhase previousGamePhase;
	sf::Shader testShader;
	sf::Texture buttonTexture;
	sf::Font buttonFont;
	bool running;
	sf::View viewport;
	std::shared_ptr<bool> GameRunning;
	std::shared_ptr<bool> ExitGame;
	std::shared_ptr<Light> pStartLight;
	std::shared_ptr<Light> pBaseLight;
	std::shared_ptr<Light> pTopLeftLight;
	std::shared_ptr<Light> pTopRightLight;
	std::shared_ptr<Light> pBottomLeftLight;
	std::shared_ptr<Light> pBottomRightLight;
public:
	GamesPhaseManager();
	GamesPhaseManager(std::shared_ptr<bool> *exit);
	void Update();
	void Draw(sf::RenderWindow *window);
	std::shared_ptr<std::vector<BaseTower>> pTowers;
	std::shared_ptr<Grid> pGrid;


};


