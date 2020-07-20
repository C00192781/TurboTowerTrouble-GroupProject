#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <string>
#include <memory>
////////////////////////////////////////////////////////////
/// \brief Button that displays text and a sprite
/// contribution: Dermot Mac Conville, Simon Dowling
////////////////////////////////////////////////////////////
class Button {
private:
	void initialize();
	sf::Vector2f m_pos; //member variables
	sf::Vector2f m_origin;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::string m_str;
	sf::Text m_text;
	sf::Font m_font;
	//will be used for sounds
	sf::SoundBuffer m_soundBuffer;
	sf::Sound m_sound;
	std::shared_ptr<sf::Texture> pTexture;
	std::shared_ptr<sf::Font> pFont;
public:
	Button();
//	Button(std::string btnString, sf::Vector2f pos);//default constructor, takes a string and a vector2f to use as the text on the button and the position for it.
	Button(std::string btnString, sf::Vector2f pos, sf::Texture tx, sf::Font fnt);//new constructor
	//too many public variables, will make them private
	void loadThings();
	
	bool pressed = false; 
	bool selected; //determine the texture for the button
	////////////////////////////////////////////////////////////
	/// \brief Button that displays text and a sprite
	///
	////////////////////////////////////////////////////////////
	void update();
	void draw(sf::RenderWindow *window); //draw method
	////////////////////////////////////////////////////////////
	/// \brief returns the button name 
	///
	////////////////////////////////////////////////////////////
	std::string String();
	////////////////////////////////////////////////////////////
	/// \brief returns the pos of the sprite
	///
	////////////////////////////////////////////////////////////
	sf::Vector2f Pos();
	////////////////////////////////////////////////////////////
	/// \brief sets the position for m_text and the sprite
	///
	////////////////////////////////////////////////////////////
	void setPos(sf::Vector2f p);
	////////////////////////////////////////////////////////////
	/// \brief sets the string in m_text
	/// \param passed string will replace the local string
	////////////////////////////////////////////////////////////
	void setString(std::string s);
};