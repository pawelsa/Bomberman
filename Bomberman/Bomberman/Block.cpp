#include "Block.h"

Block::Block(sf::Vector2f mPos, int mTypeOfBlock, Position position)
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

			Square.setTextureRect(sf::IntRect(20, 20, BlockSize.x, BlockSize.y));
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

		this->Pos = position;
	}
	catch (const std::exception& ex) {

		std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
		throw ex;
	}
}
