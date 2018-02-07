#pragma once
#include <iostream>
#include "Bomb.h"

extern sf::RenderWindow window;

class Block 
{
	
	sf::Texture *BlockTexture;
	Bomb *bomb = NULL;

public:


	sf::Sprite Square;
	bool isDestructable = false;
	bool isDestructed = false;

	const sf::Vector2i position;

	Block(sf::Vector2i mPos, int mTypeOfBlock, sf::Texture *texture) :position(mPos), BlockTexture(texture)
	{

		try 
		{
			sf::Vector2f BlockSize = sf::Vector2f(60, 60);


			/*
				Type of block:

				1	-	solid block
				2	-	destructable
				3	-	already destructed - floor block
			*/

			Square.setTexture(*BlockTexture);
			Square.setPosition((sf::Vector2f)position);

			


			if (mTypeOfBlock == 1)
			{
				
				Square.setTextureRect(sf::IntRect(20, 20, BlockSize.x,BlockSize.y));
			}
			else if (mTypeOfBlock == 2) 
			{

				Square.setTextureRect(sf::IntRect(20, 220, BlockSize.x, BlockSize.y));
			}
			else if (mTypeOfBlock == 3) 
			{
				isDestructed = true;
				Square.setTextureRect(sf::IntRect(20, 200, BlockSize.x, BlockSize.y));
			}
			


		}
		catch (const std::exception& ex){

			std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
			throw ex;
		}

	}

	bool isDestroyed() 
	{
		return isDestructed;
	}

	sf::FloatRect getGlobalBounds() 
	{

		return Square.getGlobalBounds();
	}


	void placeBomb(Bomb *mBomb) {

		bomb = mBomb;
	}

	bool isThereBomb() {

		if (bomb == NULL)
			return false;

		return true;
	}


};
