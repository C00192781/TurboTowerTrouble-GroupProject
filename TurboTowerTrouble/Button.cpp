#include "Button.h"

Button::Button()
{
}

Button::Button(std::string btnString, sf::Vector2f pos, sf::Texture tx, sf::Font fnt) : m_str(btnString), m_font(fnt), m_pos(pos), m_texture(tx), m_sprite(m_texture), m_text(m_str, m_font)
{
	m_texture.loadFromFile("button.png");
	m_sprite.setTexture(m_texture);
	m_text.setFont(m_font);
	m_sprite.setPosition(m_pos);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	m_text.setCharacterSize(20);
	m_text.setPosition(m_pos.x, m_pos.y - 8.0f); //sets the text's position right in the center of the button
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2); //gets origin of the text

}
//used to stop the texture and font going out of scope
void Button::loadThings()
{
	m_sprite.setTexture(m_texture);
	m_text.setFont(m_font); 
}


void Button::update() //if the button is selected, the alpha varies to make it fade in and out, if it is pressed, the scale changes for feedback to the user
{
	if (selected)
	{
		m_sprite.setColor(sf::Color(255, 255, 255, 200));
		m_text.setColor(sf::Color(255, 255, 255, 255));
		if (sf::Joystick::isButtonPressed(0, 0) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))) //is A is pressed
		{
			pressed = true;
		}
		else 
		{
			pressed = false;
		}


		if (pressed)
		{
			m_sound.play();
			m_sprite.setScale(0.9f, 0.9f); //make the button smaller
			m_text.setScale(0.7f, 0.9f); //make the text smaller
		}
		else
		{
			m_sprite.setScale(1.0f, 1.0f); //return to original size
			m_text.setScale(1.0f, 1.0f);
		}
	}

	if (!selected)
	{
		m_sprite.setColor(sf::Color(128,128,128,170)); //set the texture if it's not being hovered
		m_text.setColor(sf::Color(255, 255, 255, 170));
	}
}

void Button::draw(sf::RenderWindow *window) //draw method accepts pointer to a renderwindow, draws the sprite and text on top of the sprite.
{
	loadThings();
	window->draw(m_sprite);
	window->draw(m_text);
}
//get-set functions
std::string Button::String()
{
	return m_text.getString();
}
sf::Vector2f Button::Pos()
{
	return m_sprite.getPosition();
}
void Button::setPos(sf::Vector2f p)
{
	m_pos = p;
	m_sprite.setPosition(m_pos);
	m_text.setPosition(m_pos.x - 20, m_pos.y - 10);
}
void Button::setString(std::string s)
{
	m_str = s;
	m_text.setString(m_str);
}