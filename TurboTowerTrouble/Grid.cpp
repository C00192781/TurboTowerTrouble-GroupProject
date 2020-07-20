#include "Grid.h"
#include <iostream>


Grid::Grid()
{
	if (!levelTexture.loadFromFile("Sprites Folder/levelTexture.png"))
	{
		// error...
	}
	mapCount = std::shared_ptr<int>(new int(2));
	if (*mapCount == 1)
	{
		//WIP
		maxRow = 12;
		maxCol = 14;
		pMaze = (int*)maze;
	}
	if (*mapCount == 2)
	{
		maxRow = 13;
		maxCol = 18;
		pMaze = (int*)maze1;
	}
	if (*mapCount == 3)
	{
		maxRow = 13;
		maxCol = 18;
		pMaze = (int*)maze2;
	}
	maxSquares = maxRow * maxCol;
	for (int i = 0; i < maxSquares; i++)
	{
		spriteVector.push_back(sf::Sprite());
		spriteVector[i].setTexture(levelTexture);
		spriteVector[i].setPosition(-500, -500);
		spriteVector[i].setScale(0.5f, 0.5f);
	}
	CreateMap();

}

Grid::Grid(int map)
{
	mapCount = std::shared_ptr<int>(new int(map));
	if (*mapCount == 1)
	{
		//WIP
		maxRow = 12;
		maxCol = 14;
		pMaze = (int*)maze;
	}
	if (*mapCount == 2)
	{
		maxRow = 13;
		maxCol = 18;
		pMaze = (int*)maze1;
	}
	if (*mapCount == 3)
	{
		maxRow = 13;
		maxCol = 18;
		pMaze = (int*)maze2;
	}
	CreateMap();
}

void Grid::ChangeMap()
{
	*mapCount = 3;
	maxRow = 13;
	maxCol = 18;
	pMaze = (int*)maze2;
	spriteVector.resize(0);
	CreateMap();
}

////////////////////////////////////////////////////////////
/// \brief This method will be used to draw all of our tiles
/// \param	The variables are our window and shaders
////////////////////////////////////////////////////////////
void Grid::Draw(sf::RenderWindow *window, sf::Shader* shader)
{
	for (int i = 0; i < maxSquares; i++)
	{
		window->draw(spriteVector[i], shader);
	}
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief This method will be used to rotate tiles within the grid.
/// \param	The variables are the degrees we will rotate the tiles by and the index
//////////////////////////////////////////////////////////////////////////////////
void Grid::RotateImage(int degrees, int index)
{
	spriteVector[index].setOrigin(sf::Vector2f(45.5, 45.5));
	spriteVector[index].setRotation(degrees);
	spriteVector[index].setOrigin(sf::Vector2f(0, 0));
}

void Grid::CreateMap()
{
	maxSquares = maxRow * maxCol;
	for (int i = 0; i < maxSquares; i++)
	{
		spriteVector.push_back(sf::Sprite());
		spriteVector[i].setTexture(levelTexture);
		spriteVector[i].setPosition(-500, -500);
		spriteVector[i].setScale(0.5f, 0.5f);
	}
	int index = 0;
	for (int column = 0; column < maxCol; column++)
	{
		for (int row = 0; row < maxRow; row++)
		{
			if (pMaze[maxCol*(row)+column] == 0)//Single lane road
			{
				spriteVector[index].setTextureRect(sf::IntRect(270, 0, 89, 89));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 1)//Tower Base
			{
				spriteVector[index].setTextureRect(sf::IntRect(360, 0, 89, 89));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 2)//Block
			{
				spriteVector[index].setTextureRect(sf::IntRect(0, 0, 89, 89));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 3)//Upwards Left Side of Road
			{
				spriteVector[index].setTextureRect(sf::IntRect(450, 0, 89, 89));
				RotateImage(-90, index);
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, (row + 1)*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 4)//Upwards Right Side of Road
			{
				spriteVector[index].setTextureRect(sf::IntRect(450, 0, 89, 89));
				RotateImage(90, index);
				spriteVector[index].setPosition((column + 1)*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 5)//Sideways Bottom Side of Road
			{
				spriteVector[index].setTextureRect(sf::IntRect(450, 0, 89, 89));
				RotateImage(180, index);
				spriteVector[index].setPosition((column + 1)*spriteVector[index].getGlobalBounds().width, (row + 1)*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 6)//Sideways Top Side of Road
			{
				spriteVector[index].setTextureRect(sf::IntRect(450, 0, 89, 89));
				spriteVector[index].setPosition((column)*spriteVector[index].getGlobalBounds().width, (row)*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 7)// (Bottom Left of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(180, 0, 89, 89));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 8)//(Bottom Right of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(180, 0, 89, 89));
				RotateImage(-90, index);
				spriteVector[index].setPosition((column - 1)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 9)//(Top Left of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(180, 0, 89, 89));
				RotateImage(90, index);
				spriteVector[index].setPosition((column)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row - 1)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 10)//(Top Right of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(180, 0, 89, 89));
				RotateImage(-180, index);
				spriteVector[index].setPosition((column)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 11)// (Bottom Left of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(270, 90, 89, 89));
				spriteVector[index].setPosition(column*spriteVector[index].getGlobalBounds().width, row*spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 12)//(Bottom Right of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(270, 90, 89, 89));
				RotateImage(-90, index);
				spriteVector[index].setPosition((column - 1)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 13)//(Top Left of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(270, 90, 89, 89));
				RotateImage(90, index);
				spriteVector[index].setPosition((column)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row - 1)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
			if (pMaze[maxCol*(row)+column] == 14)//(Top Right of Image)Corner
			{
				spriteVector[index].setTextureRect(sf::IntRect(270, 90, 89, 89));
				RotateImage(-180, index);
				spriteVector[index].setPosition((column)*spriteVector[index].getGlobalBounds().width + spriteVector[index].getGlobalBounds().width, (row)*spriteVector[index].getGlobalBounds().height + spriteVector[index].getGlobalBounds().height);
				index++;
			}
		}
	}
}

void Grid::SetTowerBases(std::vector<TowerBase>& towerBaseVector)
{
	int index = 0;
	for (int column = 0; column < maxCol; column++)
	{
		for (int row = 0; row < maxRow; row++)
		{
			if (pMaze[maxCol*(row)+column] == 1)//Tower Base
			{
				towerBaseVector.push_back(TowerBase(sf::Vector2<int>(column*spriteVector[maxCol*(row)+column].getGlobalBounds().width, row*spriteVector[maxCol*(row)+column].getGlobalBounds().height)));
				towerBaseVector.at(index).SetSize(spriteVector[maxCol*(row)+column].getGlobalBounds().width, spriteVector[maxCol*(row)+column].getGlobalBounds().height);
				index++;
			}
		}
	}
	towerBaseVector[0].SetSelected(true);
}


const int Grid::maze[12][14]
{
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 11, 2 },
	{ 2, 3, 8, 5, 5, 5, 5, 5, 5, 5, 5, 7, 4, 2 },
	{ 2, 3, 4, 1, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2 },
	{ 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2 },
	{ 6, 9, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 10, 6 },
	{ 5, 7, 4, 1, 2, 2, 2, 2, 2, 2, 1, 3, 8, 5 },
	{ 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2 },
	{ 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2 },
	{ 2, 3, 10, 6, 6, 6, 6, 6, 6, 6, 6, 9, 4, 2 },
	{ 2, 14, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 13, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};
//////////////////////////////////////////////////////////////////////
const int Grid::maze1[13][18]
{
	{ 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 11, 2, 2, 2, 2, 2 },
	{ 6, 9, 8, 7, 8, 5, 5, 5, 5, 5, 5, 7, 4, 1, 2, 2, 2, 2 },
	{ 5, 5, 13, 3, 4, 2, 1, 1, 1, 2, 2, 3, 4, 2, 2, 2, 2, 2 },
	{ 2, 2, 1, 3, 10, 6, 6, 6, 6, 6, 6, 9, 4, 1, 2, 1, 2, 2 },
	{ 2, 2, 2, 14, 5, 5, 5, 5, 5, 5, 5, 7, 10, 6, 6, 6, 6, 6 },
	{ 2, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 3, 8, 5, 7, 8, 5, 5 },
	{ 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 3, 4, 2, 3, 4, 2, 2 },
	{ 2, 2, 2, 2, 2, 12, 6, 6, 6, 6, 6, 9, 4, 1, 3, 4, 1, 2 },
	{ 2, 2, 2, 2, 2, 3, 8, 5, 5, 5, 5, 5, 13, 2, 3, 4, 1, 2 },
	{ 2, 2, 1, 1, 2, 3, 4, 2, 1, 1, 2, 2, 2, 2, 3, 4, 2, 2 },
	{ 6, 6, 6, 6, 6, 9, 10, 6, 6, 6, 6, 6, 6, 6, 9, 4, 2, 2 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 13, 2, 2 }
};

const int Grid::maze2[13][18]
{
	{ 2, 2, 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2, 2, 2 },
	{ 2, 2, 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2, 2, 2 },
	{ 2, 12, 6, 3, 4, 6, 11, 2, 2, 2, 2, 12, 6, 3, 4, 6, 11, 2 },
	{ 2, 3, 8, 5, 5, 7, 4, 2, 2, 2, 2, 3, 8, 5, 5, 7, 4, 2 },
	{ 2, 3, 4, 1, 2, 3, 4, 1, 2, 2, 2, 3, 4, 1, 2, 3, 4, 2 },
	{ 6, 3, 4, 2, 2, 3, 4, 2, 2, 2, 2, 3, 4, 2, 2, 3, 4, 2 },
	{ 5, 3, 4, 2, 1, 3, 4, 2, 2, 2, 2, 3, 4, 2, 1, 3, 4, 2 },
	{ 2, 3, 10, 6, 6, 9, 4, 2, 2, 2, 2, 3, 10, 6, 6, 9, 4, 2 },
	{ 2, 14, 5, 3, 4, 5, 5, 2, 1, 2, 2, 14, 5, 3, 4, 5, 5, 2 },
	{ 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2 },
	{ 2, 2, 2, 5, 5, 5, 5, 5, 3, 4, 5, 5, 5, 5, 5, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 2, 2, 2, 2, 2, 2, 2, 2 }
};

std::shared_ptr<int> Grid::getMapCount()
{
	return mapCount;
}