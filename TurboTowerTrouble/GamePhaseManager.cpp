#include "GamePhaseManager.h"

GamesPhaseManager::GamesPhaseManager(std::shared_ptr<bool> *exit)
{
	tokenParticles;
	pTowers = std::make_shared<std::vector<BaseTower>>(m_towers);
	pGrid = std::make_shared<Grid>(testGrid);
	gameOver = false;
	pGameOver = &gameOver;
	m_currency = 60;
	pCurrency = std::make_shared<int>(m_currency);
	m_score = 0;
	pScore = std::make_shared<int>(m_score);

	if (!vanillaTexture.loadFromFile("Sprites Folder/Tower Sprites/ToughGuy.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!sniperTexture.loadFromFile("Sprites Folder/Tower Sprites/SniperTurret.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!uziTexture.loadFromFile("Sprites Folder/Tower Sprites/UziTurret.png"))
	{
		std::cout << "Error" << std::endl;
	}
	buttonFont.loadFromFile(".\\FallingSkyMed.otf");
	buttonTexture.loadFromFile(".\\button.png");
	running = false;
	m_menu = MainMenu(buttonTexture, buttonFont, ExitGame, GameRunning);
	m_pauseMenu = MainMenu(buttonTexture, buttonFont);
	if (!enemyTex.loadFromFile("Sprites Folder/Enemy Sprites/Scrub1.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!enemyTex2.loadFromFile("Sprites Folder/Enemy Sprites/Scrub2.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!enemyTex3.loadFromFile("Sprites Folder/Enemy Sprites/Scrub3.png"))
	{
		std::cout << "Error" << std::endl;
	}
	m_BuildPhase = BuildPhase(pGrid, vanillaTexture, sniperTexture, uziTexture);
	m_WavePhase = WavePhase(pGrid->getMapCount());
	theGamePhase = GamePhase::MainMenu;
	testShader.loadFromFile("FragmentShaderCode.glsl", sf::Shader::Fragment);
	pStartLight = std::shared_ptr<Light>(new Light(sf::Vector2f(0, 270), sf::Vector2f(0.5, 0.5), sf::Color::Red));
	pBaseLight = std::shared_ptr<Light>(new Light(sf::Vector2f(635, 270), sf::Vector2f(0.5, 0.5), sf::Color(0, 255, 0, 160)));
	pTopLeftLight = std::shared_ptr<Light>(new Light(sf::Vector2f(0, 0), sf::Vector2f(1.0, 1.0), sf::Color::Red));
	pTopRightLight = std::shared_ptr<Light>(new Light(sf::Vector2f(635, 0), sf::Vector2f(1.0, 1.0), sf::Color::Cyan));
	pBottomLeftLight = std::shared_ptr<Light>(new Light(sf::Vector2f(0, 540), sf::Vector2f(1.0, 1.0), sf::Color::Magenta));
	pBottomRightLight = std::shared_ptr<Light>(new Light(sf::Vector2f(635, 540), sf::Vector2f(1.0, 1.0), sf::Color::Yellow));
}
void GamesPhaseManager::Draw(sf::RenderWindow *window)
{
	if (theGamePhase == GamePhase::GameOver)
	{
		scr.Draw(window);
	}
	if (theGamePhase == GamePhase::Build)
	{
		pGrid->Draw(window, &testShader);
		m_BuildPhase.Draw(window, &testShader, pTowers);
		gameHud.Draw(window);
		pStartLight->draw(window);
		pBaseLight->draw(window);
		pTopLeftLight->draw(window);
		pTopRightLight->draw(window);
		pBottomLeftLight->draw(window);
		pBottomRightLight->draw(window);
	}
	if (theGamePhase == GamePhase::Wave)
	{
		pGrid->Draw(window, &testShader);
		m_WavePhase.Draw(window, &testShader, pTowers);
		gameHud.Draw(window);
		pStartLight->draw(window);
		pBaseLight->draw(window);
		pTopLeftLight->draw(window);
		pTopRightLight->draw(window);
		pBottomLeftLight->draw(window);
		pBottomRightLight->draw(window);
	}
	if (theGamePhase == GamePhase::Pause)
	{
		m_pauseMenu.draw(window);	
	}
	if (theGamePhase == GamePhase::MainMenu)
	{
	//	window->setView(window->getDefaultView());
		tokenParticles.draw(window);
		m_menu.draw(window);

	}

}

void GamesPhaseManager::Update()
{
	int bHealth;
	//checks the button message from the menu class
	//the pause has an issue
	//cannot be paused more than once while the gamephase is set to wave
	sf::Joystick::update();
	std::cout << *pCurrency << std::endl;
	if (gameOver==true)
	{
		theGamePhase = GamePhase::GameOver;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "did something" << std::endl;
	}
	if (theGamePhase == GamePhase::Build)
	{
		if (sf::Joystick::isButtonPressed(0, 7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			previousGamePhase = theGamePhase;
			theGamePhase = GamePhase::Pause;
		}
		bHealth = m_WavePhase.getTowerHealth();
		gameHud.Update(pCurrency, pScore, bHealth);
		m_BuildPhase.Update(pTowers,pCurrency);

		if (m_BuildPhase.getStartWave() == true)
		{

			theGamePhase = GamePhase::Wave;
			m_BuildPhase.setStartWave(false);
		}
	}
	if (theGamePhase == GamePhase::Wave)
	{
		bHealth = m_WavePhase.getTowerHealth();
		if (sf::Joystick::isButtonPressed(0, 7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			previousGamePhase = theGamePhase;
			theGamePhase = GamePhase::Pause;
			gameHud.Update(pCurrency, pScore, bHealth);
		}
		gameHud.Update(pCurrency, pScore, bHealth);
		m_WavePhase.Update(pTowers, pCurrency, pScore, pGameOver);
		int temp = m_WavePhase.getWaveState();
		if(temp==1)
		{
			theGamePhase = GamePhase::Build;
			m_WavePhase.waveState = 0;
		}
		if (temp == 2)
		{
			pTowers->clear();
			pTowers->shrink_to_fit();
			pGrid->ChangeMap();
			m_BuildPhase.setTowerBases(pGrid);
			m_BuildPhase.setStartWave(false);
			m_WavePhase.waveState = 0;
			theGamePhase = GamePhase::Build;
		}
		if (temp == 3)
		{
			theGamePhase = GamePhase::Exit;
		}
		
	}
	if (theGamePhase == GamePhase::Pause)
	{
		if (m_pauseMenu.Message == "Resume")
		{
			
			theGamePhase = previousGamePhase;
			previousGamePhase = GamePhase::Pause;
			m_pauseMenu.Message = "";
		}
		m_pauseMenu.update();
	}
	if (theGamePhase == GamePhase::MainMenu)
	{
		if (m_menu.Message == "Build")
			theGamePhase = GamePhase::Build;
		else if (m_menu.Message == "Exit")
			theGamePhase = GamePhase::Exit;
		tokenParticles.update();
		m_menu.update();
	}
}

