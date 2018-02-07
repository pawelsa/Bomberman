#pragma once
#include "Block.h"
#include "Player.h"


class Manager {

	//			   Y  X
	Block *blocks[11][15];
public:
	Player myPlayer;

	Manager() {

		try {

			dim::BlockTexture.loadFromFile("solidBricks.jpg");


			for (int mY = 0; mY < 11; mY++) {

				for (int mX = 0; mX < 15; mX++) {
				
					blocks[mY][mX] = NULL;
				}
			}

			for (int mY = 0; mY < 11; mY++) {

				for (int mX = 0; mX < 15; mX++) {

					if ((mY % 2 == 0 && mX % 2 == 0) || mY == 0 || mX == 0 || mY == 10 || mX == 14) {
					
						blocks[mY][mX] = new Block(sf::Vector2f(mX*dim::BlockSize.x, mY*dim::BlockSize.y), 1);
					}
					else if (blocks[mY][mX] == NULL) {

						blocks[mY][mX] = new Block(sf::Vector2f(mX*dim::BlockSize.x, mY*dim::BlockSize.y), 3);
					}
				}
			}
	

		}
		catch (const std::exception& ex) {

			std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
			throw ex;
		}


	}

	void display() {

		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {
		
				blocks[mY][mX]->display();
			}
		}

		collision();
		
	}


	bool collision() {


		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {
				
				if (myPlayer.PlayerAnimatedSprite.getGlobalBounds().intersects(blocks[mY][mX]->getGlobalBounds()) && !blocks[mY][mX]->isDestroyed()) {

					std::cout << "Collision!\n\n";
					return true;
				}
			}
		}

		return false;
	}

	void plantBomb(int playerWhoPlanted) {

					//trzeba potem tu ustawic drugiego gracza	\/
		Player *bomber = playerWhoPlanted == 1 ? &myPlayer : &myPlayer;

		sf::Vector2i bomberPosition_CenterOfBody =
			sf::Vector2i(bomber->PlayerAnimatedSprite.getGlobalBounds().left + bomber->PlayerAnimatedSprite.getGlobalBounds().width / 2,
				bomber->PlayerAnimatedSprite.getGlobalBounds().top + bomber->PlayerAnimatedSprite.getGlobalBounds().height / 2);

		if (bomberPosition_CenterOfBody.x > 0 && bomberPosition_CenterOfBody.x < 15 
			&& bomberPosition_CenterOfBody.y>0 && bomberPosition_CenterOfBody.y < 11) {

			blocks[bomberPosition_CenterOfBody.y][bomberPosition_CenterOfBody.x]->plantBomb(new Bomb(bomberPosition_CenterOfBody));
		}


	}

};
