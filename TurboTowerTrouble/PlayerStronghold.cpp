#include "PlayerStronghold.h"

PlayerStronghold::PlayerStronghold()
{

}
PlayerStronghold::PlayerStronghold(sf::Vector2f pos, sf::Vector2f spritePos, int startingHealth, sf::Texture & Texture) :damagePoint(pos), position(spritePos), health(startingHealth), t(Texture)
{
	sprite = sf::Sprite(t);
	sprite.setPosition(position);
	sprite.setColor(sf::Color(255,255,255,255));
}
void PlayerStronghold::Update()
{

	if (health <=0)
	{
		//sprite.setColor(sf::Color(sprite.getColor().r*-1, sprite.getColor().g*-1, sprite.getColor().b*-1,255)); well intentioned, but broken

	}
}
void PlayerStronghold::Draw(sf::RenderWindow *window)
{
	sprite.setTexture(t);
	window->draw(sprite);
}
void PlayerStronghold::TakeDamage()
{
	health -= 10;
	sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g - 25, sprite.getColor().b - 25, 255));
}
int PlayerStronghold::getHealth()
{
	return health;
}
sf::Vector2f PlayerStronghold::getDamagePoint()
{
	return damagePoint;
}
void PlayerStronghold::setHealth(int newHealth)
{
	health = newHealth;
}
void PlayerStronghold::setPosition(sf::Vector2f newDamagePoint, sf::Vector2f newSpriteFont)
{
	damagePoint = newDamagePoint;
	position = newSpriteFont;
}
PlayerStronghold::~PlayerStronghold()
{
}

sf::Sprite PlayerStronghold::getSprite()
{
	return sprite;
}