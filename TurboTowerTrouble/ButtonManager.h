#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>
#include "Button.h"
#include <memory>
#pragma once
////////////////////////////////////////////////////////////
/// \brief Manages all buttons, creates and destroys buttons
///
/// contributions: Dermot Mac Conville
////////////////////////////////////////////////////////////
class ButtonManager
{
private:
	//pointer to the vector of buttons in main menu
	std::vector<Button> * btnVector;
	//unused, will remove
	sf::Vector2f padInput;
	sf::Font *font;
	sf::Texture *texture;
	sf::SoundBuffer buttonMove;
	sf::Sound sound;
	//the text in the currently selected button, used for case checking
	std::string selectedButtonText;

	int selected;
	

	bool buttonPressed;
	sf::Event event;
	//Button tempButton;
	bool playsound;

	float timer = 25;
	bool keyboardPressed = false;
	bool timerIncrease = false;
public:
	int totalButtonCount;
	ButtonManager(std::vector<Button> &btn, sf::Font &fn, sf::Texture &tx);
	ButtonManager();
	void update(std::vector<Button> *buttonPointer);
	////////////////////////////////////////////////////////////
	/// \brief returns the button name to the main menu, not used yet
	///
	////////////////////////////////////////////////////////////
	std::string getButtonName(std::vector<Button>* buttonPointer);
	//not used yet
	void removeButton(std::string btnName);
	////////////////////////////////////////////////////////////
	/// \brief creates a new button and allocates it in a vector, remember to reserve space before calling if you need to
	///
	////////////////////////////////////////////////////////////
	void MakeNewButton(std::string text, sf::Vector2f pos);
	~ButtonManager();
};

