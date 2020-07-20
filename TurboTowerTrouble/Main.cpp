#include "GamePhaseManager.h"

int main()
{
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Turbo Tower Trouble!!!");
	window->setFramerateLimit(60);
	bool exit = false;
	std::shared_ptr<bool> exitGame(&exit);
	GamesPhaseManager game(&exitGame);

	while (exit==false)
	{
		game.Update();
		window->clear();
		game.Draw(window);
		window->display();
	}
}