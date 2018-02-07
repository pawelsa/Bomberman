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

		BlockTexture.loadFromFile("solidBricks.jpg");

		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {

				if ((mY % 2 == 0 && mX % 2 == 0) || mY == 0 || mX == 0 || mY == 10 || mX == 14)
				{
					Position positonOfBlockToAdd = Position(mX, mY);
					Blocks.push_front(new Block(1, positonOfBlockToAdd, &BlockTexture));

				}
				else 
				{
					Position positonOfBlockToAdd = Position(mX, mY);
					Blocks.push_front(new Block(3, positonOfBlockToAdd, &BlockTexture));
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
	sf::Vector2i centerOfPlayerBody = sf::Vector2i(myPlayer->PlayerAnimatedSprite.getGlobalBounds().left + myPlayer->PlayerAnimatedSprite.getGlobalBounds().width / 2,
		myPlayer->PlayerAnimatedSprite.getGlobalBounds().top + myPlayer->PlayerAnimatedSprite.getGlobalBounds().height / 2);

	Position playerOnArena((int)centerOfPlayerBody.x / BlockSize.x, (int)centerOfPlayerBody.y / BlockSize.y);
	
	//sprawdza czy nie byla tu juz stworzona, wczesniej robily sie po 2 na jedno pole nwm dlaczego
	auto listOfBombs = BombList;

	for (Bomb* bomb : listOfBombs)
	{
		if (bomb->getPosition() == playerOnArena) {

			return;
		}
	}

	BombList = listOfBombs;

	Bomb* bombToAdd = new Bomb(playerOnArena);
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
			std::cout << "BOOM\n\n";
		}
	}
	BombList = listOfBombs;
}


