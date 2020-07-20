#include <SFML/Graphics.hpp>
/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Matthew Watson
////////////////////////////////////////////////////////////
class TowerBase
{

public:
	TowerBase();
	TowerBase(sf::Vector2<int> p);
	void Draw(sf::RenderWindow *window);
	/////////////////////////////////////////
	//
	// \Brief sets the position of the rectangle
	//
	/////////////////////////////////////////
	void SetPosition(sf::Vector2<int> position);
	sf::Vector2f getPosition();
	void SetSize(float width, float height);
	void SetSelected(bool selected);
	bool selected = false;
	bool hasTower = false;
private:
	//position for the Tower Base.
	sf::Vector2f position;
	sf::RectangleShape rect;
	
};