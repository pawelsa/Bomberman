#pragma once

#include <iostream>
#include "Position.h"
#include "SFML\Graphics.hpp"


class Block 
{


	
	sf::Texture BlockTexture;

public:
	sf::Sprite Square;
	Position Pos;

	bool isDestructable = false;
	bool isDestructed = false;
	Block(sf::Vector2f mPos, int mTypeOfBlock, Position position);

	bool isDestroyed() 
	{
		return isDestructed;
	}

	sf::FloatRect getGlobalBounds() 
	{
		return Square.getGlobalBounds();
	}
};
