#pragma once

#include <iostream>
#include "Position.h"
#include "SFML\Graphics.hpp"


class Block
{
public:
	sf::Texture BlockTexture;
	Block() {};

	sf::Sprite Square;
	const Position Pos;

	bool isDestructable = false;
	bool isDestructed = true;
	Block(Position position);


	bool isDestroyed() 
	{
		return isDestructed;
	}

	sf::FloatRect getGlobalBounds() 
	{
		return Square.getGlobalBounds();
	}

	sf::Vector2f getSquarePosition()
	{
		return Square.getPosition();
	}
	
};
