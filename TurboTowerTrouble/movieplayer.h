#pragma once


#include <sfeMovie\Movie.hpp>
#include <sfeMovie\StreamSelection.hpp>
#include <sfeMovie\Visibility.hpp>
class movieplayer
{
public:
	movieplayer();
	sfe::Movie mov;
	void update();
	~movieplayer();
};

