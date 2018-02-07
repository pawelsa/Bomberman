#include "Manager.h"

Manager::Manager()
{
	Init();
}

Manager::~Manager()
{
}

void Manager::GameLoop()
{
	while (UIM.window->isOpen())
	{
		sf::Event event;
		
		UIM.window->clear();

		while (UIM.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				UIM.window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{

				myPlayer->MoveUp();
				for (Block* block : Blocks)
				{
					if (myPlayer->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)

							myPlayer->MoveDown();
						
				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				myPlayer->MoveDown();
				for (Block* block : Blocks)
				{
					
					if (myPlayer->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)

							myPlayer->MoveUp();

				}

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				myPlayer->MoveLeft();
				for (Block* block : Blocks)
				{
					if (myPlayer->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)

							myPlayer->MoveRight();
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				myPlayer->MoveRight();
				for (Block* block : Blocks)
				{
					if (myPlayer->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)

							myPlayer->MoveLeft();

				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {

				plantBomb();
			}

		}
		UIM.DrawBlocks(GetBlocks());
		UIM.DrawPlayer(myPlayer);
		UIM.window->display();
	}
}

void Manager::Init()
{
	try {

		sf::Vector2f BlockSize = sf::Vector2f(60, 60);

		BlockTexture.loadFromFile("solidBricks.jpg");

		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {

				if ((mY % 2 == 0 && mX % 2 == 0) || mY == 0 || mX == 0 || mY == 10 || mX == 14)
				{
					Blocks.push_back(new Block(sf::Vector2i(mX*BlockSize.x, mY*BlockSize.y), 1, &BlockTexture));

				}
				else 
				{

					Blocks.push_back(new Block(sf::Vector2i(mX*BlockSize.x, mY*BlockSize.y), 3, &BlockTexture));
				}
			}
		}

		myPlayer = new Player();


	}
	catch (const std::exception& ex) {

		std::cout << "error occured durning initialization of a player" << ex.what() << std::endl;
		throw ex;
	}
}


std::vector<Block*> Manager::GetBlocks()
{
	return Blocks;
}

void Manager::plantBomb() {


	sf::Vector2i centerOfPlayerBody = sf::Vector2i(myPlayer->PlayerAnimatedSprite.getGlobalBounds().left+myPlayer->PlayerAnimatedSprite.getGlobalBounds().width/2,
		myPlayer->PlayerAnimatedSprite.getGlobalBounds().top + myPlayer->PlayerAnimatedSprite.getGlobalBounds().height / 2);


	centerOfPlayerBody = sf::Vector2i(centerOfPlayerBody.x / BlockSize.x, centerOfPlayerBody.y / BlockSize.y);

	for (int i = 0; i < Blocks.size(); i++) {
	
		if (Blocks.at(i)->position == centerOfPlayerBody) {
		
			Blocks.at(i)->placeBomb(new Bomb(centerOfPlayerBody));
		}

	}

}

/*
bool Manager::collision() {



	for (Block *mblock : Blocks) {

		if(mblock->getGlobalBounds().intersects(myPlayer->PlayerAnimatedSprite.getGlobalBounds()) && !mblock->isDestroyed()) {

			std::cout << "collision by myPlayer1 with block\n\n";
			return true;
		}

		//trzeba tu potem zamienic jak bedzie drugi gracz
		/*if (mblock->getGlobalBounds().intersects(myPlayer->PlayerAnimatedSprite.getGlobalBounds())) {

			std::cout << "collision by myPlayer2 with block";
			return true;
		}*/

		//dodac jak bedzie juz drugi gracz
		/*if (myPlayer->PlayerAnimatedSprite.getGlobalBounds().intersects(myPlayer2.PlayerAnimatedSprite.getGlobalBounds())) {
			
			std::cout << "collision between players";
			return true;
		}*/
/*

	}


}*/
