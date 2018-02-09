#pragma once
#include "Block.h"
class HardBlock :
	public Block
{
public:
	HardBlock();

	HardBlock(Position position) : Block(position)
	{
		try
		{
			sf::Vector2f BlockSize = sf::Vector2f(60, 60);


			BlockTexture.loadFromFile("Images/Blocks.png");

			Square.setTexture(BlockTexture);
			Square.setPosition(sf::Vector2f(position.X*BlockSize.x, position.Y*BlockSize.y));

			isDestructed = false;
			isDestructable = false;
			Square.setTextureRect(sf::IntRect(60, 0, BlockSize.x, BlockSize.y));
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning initialization of a block" << ex.what() << std::endl;
			throw ex;
		}
		this->isDestructable = false;
	}
	~HardBlock();
};

