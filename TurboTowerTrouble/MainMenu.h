
#include "ButtonManager.h"
#include <memory>

////////////////////////////////////////////////////////////
/// \brief Manages the menus 
/// contributions:Dermot Mac Conville
////////////////////////////////////////////////////////////

class MainMenu
{
private:
	//unsigned int m_currentButton = 0;

	std::shared_ptr<sf::Font> font;
	std::shared_ptr<sf::Texture> buttonImage;
	//text was used for debugging, no longer used
	sf::Text debugText;
	//none of these are needed will be removed
	Button playButton, optionsButton, exitButton, templateButton;
	//manager of buttons, updates, creates and destroys them
	ButtonManager Manager;
	std::shared_ptr<bool> exit;
	std::shared_ptr<bool> gameRunning;

	std::string currentButton;
	//vector that stores all the buttons
	std::vector<Button> buttonVectors;

//	Menu(sf::RenderWindow* window);
public:
	MainMenu();
	MainMenu(sf::Texture tx, sf::Font fn, std::shared_ptr <bool> pExit, std::shared_ptr <bool> pRunning);
	MainMenu(sf::Texture tx, sf::Font fn);
	void update();
	void draw(sf::RenderWindow *window);
	std::string Message;

};
