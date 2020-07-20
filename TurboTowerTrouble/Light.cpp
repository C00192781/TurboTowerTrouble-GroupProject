#include "Light.h"
////////////////////////////////////////////////////////////
/// \brief all member variables are initialized and set.
///
////////////////////////////////////////////////////////////
Light::Light()
{

}
Light::Light(sf::Vector2f pos, sf::Vector2f scale, sf::Color color) 
{
	m_pos = pos;
	m_scale = scale;
	m_color = color;
	m_lightMapTexture.create(1280, 720);
	m_lightMap.setTexture(m_lightMapTexture.getTexture());

	m_lightTexture.loadFromFile("light.png");
	m_lightTexture.setSmooth(true);

	m_lightMap.setTexture(m_lightTexture);
	m_lightMap.setTextureRect(sf::IntRect(0, 0, 512, 512));
	m_lightMap.setOrigin(256, 256);
	m_lightMap.setPosition(m_pos);
	m_lightMap.setScale(m_scale);
	m_lightMap.setColor(m_color);
}
////////////////////////////////////////////////////////////
/// \brief Draw method draws the sprite and uses sf::BlendMode
///
////////////////////////////////////////////////////////////
void Light::draw(sf::RenderWindow *window)
{
	window->draw(m_lightMap, sf::BlendAdd);
}