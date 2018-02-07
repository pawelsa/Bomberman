#include "Block.h"

Block::Block( int mTypeOfBlock, Position position, sf::Texture *texture):Pos(position)
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

		BlockTexture = texture;

		Square.setTexture(*BlockTexture);
		Square.setPosition(sf::Vector2f(position.X*BlockSize.x, position.Y*BlockSize.y));


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

	}
	catch (const std::exception& ex) {

		std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
		throw ex;
	}
}

