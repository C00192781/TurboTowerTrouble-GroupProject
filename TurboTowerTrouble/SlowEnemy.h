////////////////////////////////////////////////////////////
// First enemy type. 
// Contributors: Simon Dowling
//
////////////////////////////////////////////////////////////
#include "BaseEnemy.h"
//#include "EnemyAI.h"

class SlowEnemy :public BaseEnemy
{
public:
	SlowEnemy();
	SlowEnemy(sf::Texture &texture);
	void update();
	void draw(sf::RenderWindow *window);
	sf::Vector2f getPosition();
	std::shared_ptr<int> getHealthPointer();
	std::shared_ptr<sf::Sprite>getEnemySprite();
	int getHealth();
	void setHealth(int health);
private:
	EnemyAI m_enemyAI;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::RectangleShape m_healthBar; //a UI element so the player will know how much health the peep has.
	sf::Vector2f m_position;
	std::shared_ptr<sf::Vector2f> pPosition;

};