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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && myPlayer->BombNumber != 0)
			{
				PlaceABomb();
			}

		}
		BombHandling();
		FireHandling();
		UIM.DrawBlocks(GetBlocks());
		UIM.DrawPlayer(myPlayer);
		UIM.DrawBombs(BombList);
		UIM.DrawFire(FireList);
		UIM.window->display();
	}
}

void Manager::Init()
{
	try {

		sf::Vector2f BlockSize = sf::Vector2f(60, 60);

		BlockTexture.loadFromFile("Images/Blocks.png");

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
	bool canBePlaced = true;
	sf::Vector2i centerOfPlayerBody = sf::Vector2i(myPlayer->PlayerAnimatedSprite.getGlobalBounds().left + myPlayer->PlayerAnimatedSprite.getGlobalBounds().width / 2,
		myPlayer->PlayerAnimatedSprite.getGlobalBounds().top + myPlayer->PlayerAnimatedSprite.getGlobalBounds().height / 2);

	Position playerOnArena((int)centerOfPlayerBody.x / BlockSize.x, (int)centerOfPlayerBody.y / BlockSize.y);

	Bomb* bombToAdd = new Bomb(playerOnArena);
	for (Bomb* bomb : BombList)
	{
		if (bomb->getPosition().X == bombToAdd->getPosition().X && bomb->getPosition().Y == bombToAdd->getPosition().Y)
		{
			canBePlaced = false;
		}

	}
	if (canBePlaced)
	{
		BombList.push_front(bombToAdd);
		myPlayer->BombNumber--;
	}

	
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
			ExplodeBomb(bomb);
			myPlayer->BombNumber++;
		}
	}
	BombList = listOfBombs;
}

void Manager::ExplodeBomb(Bomb * bomb)
{
	Position bombPosition = bomb->getPosition();
	Position chceckon(bombPosition.X + 1, bombPosition.Y);
	Position chceckon1(bombPosition.X - 1, bombPosition.Y);
	Position chceckon2(bombPosition.X , bombPosition.Y + 1);
	Position chceckon3(bombPosition.X, bombPosition.Y -1);

	if (GetBlock(chceckon)->isDestroyed() == true)
	{
		Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
		FireList.push_front(fireToAdd);
	}
		
	if (GetBlock(chceckon1)->isDestroyed() == true)
	{
		Fire* fireToAdd = new Fire(GetBlock(chceckon1)->getSquarePosition());
		FireList.push_front(fireToAdd);

	}
	if (GetBlock(chceckon2)->isDestroyed() == true)
	{
		Fire* fireToAdd = new Fire(GetBlock(chceckon2)->getSquarePosition());
		FireList.push_front(fireToAdd);

	}
	if (GetBlock(chceckon3)->isDestroyed() == true)
	{
		Fire* fireToAdd = new Fire(GetBlock(chceckon3)->getSquarePosition());
		FireList.push_front(fireToAdd);
	}
		
}

Block* Manager::GetBlock(Position position)
{
	for (Block* block : Blocks)
	{
		if (block->Pos.X == position.X && block->Pos.Y == position.Y)
			return block;
	}
}

void Manager::FireHandling()
{
	auto tempList = FireList;
	for (Fire* myFire : FireList)
	{
		myFire->FireTimer();
		if (myFire->FireLifeTime == 0)
		{
			tempList.remove(myFire);
		}

	}
	FireList = tempList;

}


