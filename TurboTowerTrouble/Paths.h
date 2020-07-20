#include "SFML/Graphics.hpp"
#include <memory>
/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors:  Kevin Boylan, Matthew Watson
////////////////////////////////////////////////////////////
class Paths
{
public:
	static std::shared_ptr<std::vector<sf::Vector2f>>getPath(int mapCount, int firstPath, int secondPath);
};