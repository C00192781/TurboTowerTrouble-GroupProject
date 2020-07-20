#include "SFML/Graphics.hpp" 
#include "TowerBase.h"
#include <memory>
/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors: Kevin Boylan, Matthew Watson
////////////////////////////////////////////////////////////
class Grid
{
public:
	Grid();
	Grid(int map);
	int *pMaze;
	void Draw(sf::RenderWindow *window, sf::Shader *shader);
	void RotateImage(int degrees, int index);
	void CreateMap();
	int GetMaxSquares();
	void SetTowerBases(std::vector<TowerBase>& towerBaseVector);
	std::shared_ptr<int> getMapCount();
	void ChangeMap();
private:
	int maxCol;
	int maxRow;
	int maxSquares;
	//series of maps, initialized as 2d arrays

	static const int maze[12][14];
	static const int maze1[13][18];
	static const int maze2[13][18];
	std::vector<sf::Sprite> spriteVector;
	sf::Texture levelTexture;
	std::shared_ptr<int> mapCount;
};