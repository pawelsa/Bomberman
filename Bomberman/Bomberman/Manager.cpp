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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				PlaceABomb();
			}

		}
		BombHandling();
		UIM.DrawBlocks(GetBlocks());
		UIM.DrawPlayer(myPlayer);
		UIM.DrawBombs(BombList);
		UIM.window->display();
	}
}

void Manager::Init()
{
	try {

		sf::Vector2f BlockSize = sf::Vector2f(60, 60);


		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {

				if ((mY % 2 == 0 && mX % 2 == 0) || mY == 0 || mX == 0 || mY == 10 || mX == 14)
				{
					sf::Vector2f coordinatesOfBlockToAdd = sf::Vector2f(mX*BlockSize.x, mY*BlockSize.y);
					Position positonOfBlockToAdd = Position(mX, mY);
					Blocks.push_front(new Block(coordinatesOfBlockToAdd, 1, positonOfBlockToAdd));

				}
				else 
				{
					sf::Vector2f coordinatesOfBlockToAdd = sf::Vector2f(mX*BlockSize.x, mY*BlockSize.y);
					Position positonOfBlockToAdd = Position(mX, mY);
					Blocks.push_front(new Block(coordinatesOfBlockToAdd, 3, positonOfBlockToAdd));
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


std::list<Block*> Manager::GetBlocks()
{
	return Blocks;
}

void Manager::PlaceABomb()
{
	auto playerPosition = myPlayer->PlayerAnimatedSprite.getPosition();
	Bomb* bombToAdd = new Bomb(playerPosition);
	BombList.push_front(bombToAdd);
}

void Manager::BombHandling()
{
	auto listOfBombs = BombList;
	for (Bomb* bomb : BombList)
	{
		bomb->BombTimer();
		if (bomb->BombLifetime == 0)
		{
			listOfBombs.remove(bomb);
		}
	}
	BombList = listOfBombs;
}


