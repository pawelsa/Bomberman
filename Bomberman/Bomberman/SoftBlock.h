#pragma once
#include "Block.h"
class SoftBlock :
	public Block
{
public:
	SoftBlock();
	SoftBlock(Position position) : Block(position)
	{
		try
		{
			sf::Vector2f BlockSize = sf::Vector2f(60, 60);


			BlockTexture.loadFromFile("Images/Blocks.png");

			Square.setTexture(BlockTexture);
			Square.setPosition(sf::Vector2f(position.X*BlockSize.x, position.Y*BlockSize.y));

			isDestructed = false;
			isDestructable = true;
			Square.setTextureRect(sf::IntRect(120, 0, BlockSize.x, BlockSize.y));
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning initialization of a block" << ex.what() << std::endl;
			throw ex;
		}
		
	}
	~SoftBlock();
};

