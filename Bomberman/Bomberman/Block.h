#pragma once

#include <iostream>
#include "Position.h"
#include "SFML\Graphics.hpp"


class Block 
{


	
	sf::Texture *BlockTexture;

public:
	sf::Sprite Square;
	const Position Pos;

	bool isDestructable = false;
	bool isDestructed = false;
	Block(int mTypeOfBlock, Position position, sf::Texture *texture);


	bool isDestroyed() 
	{
		return isDestructed;
	}

	sf::FloatRect getGlobalBounds() 
	{
		return Square.getGlobalBounds();
	}
};
