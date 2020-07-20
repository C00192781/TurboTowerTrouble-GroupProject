////////////////////////////////////////////////////////////
/// \brief A light class that takes a very simple image,
///		   scales it, sets position, sets color, and draws.
///        Only needs a constructor and draw method.
///
///  Contributors: Simon Dowling
////////////////////////////////////////////////////////////
#include "SFML\Graphics.hpp"
#include "SFML\Graphics\BlendMode.hpp"

class Light
{
private:
	sf::Texture m_lightTexture, m_light;
	sf::RenderTexture m_lightMapTexture;
	sf::Sprite m_lightMap;
	sf::Vector2f m_pos, m_scale;
	sf::Color m_color;
public:
	Light();
	Light(sf::Vector2f pos, sf::Vector2f scale, sf::Color color);
	void draw(sf::RenderWindow *window);

};