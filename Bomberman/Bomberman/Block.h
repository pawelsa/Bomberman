#pragma once
#include "Dimensions.h"
#include <iostream>

extern sf::RenderWindow window;

class Block 
{


	
	sf::Texture BlockTexture;


public:
	sf::Sprite Square;
	bool isDestructable = false;
	bool isDestructed = false;
	Block(sf::Vector2f mPos, int mTypeOfBlock) 
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
			BlockTexture.loadFromFile("solidBricks.jpg");

			Square.setTexture(BlockTexture);
			Square.setPosition(mPos);


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
};
