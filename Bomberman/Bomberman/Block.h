#pragma once
#include "Dimensions.h"
#include <iostream>
#include "Bomb.h"

extern sf::RenderWindow window;

class Block {

	sf::Sprite Square;

	bool isDestructable = false;
	bool isDestructed = false;

	Bomb *theBomb = NULL;


public:

	Block(sf::Vector2f mPos, int mTypeOfBlock) {

		try {

			/*
			
				Type of block:

				1	-	solid block
				2	-	destructable
				3	-	already destructed - floor block

			*/
			
			Square.setTexture(dim::BlockTexture);
			Square.setPosition(mPos);


			if (mTypeOfBlock == 1) {
				
				Square.setTextureRect(sf::IntRect(20, 20, dim::BlockSize.x, dim::BlockSize.y));
			}
			else if (mTypeOfBlock == 2) {

				Square.setTextureRect(sf::IntRect(20, 220, dim::BlockSize.x, dim::BlockSize.y));
			}
			else if (mTypeOfBlock == 3) {

				isDestructed = true;
				Square.setTextureRect(sf::IntRect(20, 200, dim::BlockSize.x, dim::BlockSize.y));
			}
			


		}
		catch (const std::exception& ex){

			std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
			throw ex;
		}

	}

	bool isDestroyed() {

		return isDestructed;
	}

	sf::FloatRect getGlobalBounds() {

		return Square.getGlobalBounds();
	}

	void display() {

		window.draw(Square);
	}

	void plantBomb(Bomb *mBomb) {

		theBomb = mBomb;
	}


};
