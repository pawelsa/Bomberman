#include "Manager.h"

Manager::Manager()
{
	Init();
}

Manager::~Manager()
{
}

bool Manager::GameLoop()
{
	try
	{
		UIM.CreateWindow();
		while (UIM.window->isOpen())
		{
			sf::Event event;

			UIM.window->clear();

			while (UIM.window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					UIM.window->close();

				FirstPlayerHandling();
				SecondPlayerHandling();

			}
			BombHandling();
			FireHandling();
			UIM.DrawBlocks(GetBlocks());
			UIM.DrawBombs(BombList);
			UIM.DrawPlayers(PlayerList);
			UIM.DrawFire(FireList);
			UIM.window->display();
			CheckPlayersAndFire();
			if (PlayerList.size() != 2)
			{
				return true;
			}
		}
	}
	catch (const std::exception& ex)
	{
		throw ex;
	}
	
}

bool Manager::InitIntro()
{
	this->UIM.CreateWindow();
	sf::Texture BombermanIntro;
	
	sf::Text PressAnyKeyText;
	sf::Sprite BombermanIntroSprite;
	sf::Font MyFont;
	try
	{
		BombermanIntro.loadFromFile("Images/Intro.png");
		BombermanIntroSprite.setTexture(BombermanIntro);
		MyFont.loadFromFile("Images/prstartk.ttf");
		PressAnyKeyText.setString("Press X to play");
		PressAnyKeyText.setFont(MyFont);
		PressAnyKeyText.setPosition(20, 500);
		PressAnyKeyText.setCharacterSize(40);

		while (UIM.window->isOpen())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				UIM.window->close();
				return true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				UIM.window->close();
				return false;
			}
			UIM.window->draw(BombermanIntroSprite);
			UIM.window->draw(PressAnyKeyText);
			UIM.window->draw(PressAnyKeyText);
			UIM.window->display();
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << "error occured durning loading sprite" << ex.what() << std::endl;
		throw ex;

	}
	return false;
}

void Manager::ErrorPopOut(const std::exception & ex)
{

	UiManager tempUI;

	sf::Text ErrorMessage;
	sf::Text ExitText;
	ExitText.setString("Exception occured, press space to exit");
	ExitText.setPosition(20, 500);
	ExitText.setCharacterSize(15);
	sf::Font MyFont;

	ExitText.setFont(MyFont);


	MyFont.loadFromFile("Images/prstartk.ttf");

	tempUI.CreateWindow();

	std::string tempString = ex.what();
	std::string errorMessage = "Error Message: " + tempString;
	ErrorMessage.setString(errorMessage);
	ErrorMessage.setPosition(20, 550);
	ErrorMessage.setCharacterSize(15);
	ErrorMessage.setFont(MyFont);

	bool exit = false;

	while (!exit)
	{
		tempUI.window->clear();
		tempUI.window->draw(ExitText);
		tempUI.window->draw(ErrorMessage);

		tempUI.window->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			exit = true;

	}
}

void Manager::InitEndGameWindow()
{
	this->UIM.CreateWindow();
	sf::Texture BombermanIntro;

	sf::Text PressAnyKeyText;
	sf::Sprite BombermanIntroSprite;
	sf::Font MyFont;
	try
	{
		auto message = std::to_string( PlayerList.at(0)->PlayerId) + " Won!";
		BombermanIntro.loadFromFile("Images/Intro.png");
		BombermanIntroSprite.setTexture(BombermanIntro);
		MyFont.loadFromFile("Images/prstartk.ttf");
		PressAnyKeyText.setString(message);
		PressAnyKeyText.setFont(MyFont);
		PressAnyKeyText.setPosition(50, 500);
		PressAnyKeyText.setCharacterSize(40);

		while (UIM.window->isOpen())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				UIM.window->close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				UIM.window->close();
			}
			UIM.window->draw(BombermanIntroSprite);
			UIM.window->draw(PressAnyKeyText);
			UIM.window->draw(PressAnyKeyText);
			UIM.window->display();
		}

	}
	catch (const std::exception& ex)
	{
		std::cout << "error occured " << ex.what() << std::endl;
		throw ex;

	}
}

void Manager::CheckPlayersAndFire()
{
	auto templist = PlayerList;
	for (Player* player : PlayerList)
	{
		for (Fire* myFire : FireList)
		{
			//PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds())
			if (myFire->FireSprite.getGlobalBounds().intersects(player->PlayerAnimatedSprite.getGlobalBounds()))
				templist.erase(std::remove(templist.begin(), templist.end(), player), templist.end());
		}

	}
	PlayerList = templist;
}

void Manager::Init()
{
	try {

		sf::Vector2f BlockSize = sf::Vector2f(60, 60);

		
		for (int mY = 0; mY < 11; mY++) {

			for (int mX = 0; mX < 15; mX++) {

				if ((mY % 2 == 0 && mX % 2 == 0) || mY == 0 || mX == 0 || mY == 10 || mX == 14)
				{
					Position positonOfBlockToAdd = Position(mX, mY);
					Blocks.push_front(new HardBlock(positonOfBlockToAdd));
				}
				else 
				{
					Position positonOfBlockToAdd = Position(mX, mY);
					if (!((mX == 1 && mY == 1) || (mX == 2 && mY == 1) || (mX == 1 && mY == 2) || (mX == 13 && mY == 9) || (mX == 13 && mY == 8) || (mX == 12 && mY == 9)))
						Blocks.push_front(new SoftBlock(positonOfBlockToAdd));
					else
						Blocks.push_front(new Block( positonOfBlockToAdd));

				}
			}
		}

		
	
		PlayerList.push_back(new Player(1));
		PlayerList.push_back(new Player(2));



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

void Manager::PlaceABomb(Player* player)
{
	bool canBePlaced = true;
	sf::Vector2i centerOfPlayerBody = sf::Vector2i(player->PlayerAnimatedSprite.getGlobalBounds().left + player->PlayerAnimatedSprite.getGlobalBounds().width / 2,
		player->PlayerAnimatedSprite.getGlobalBounds().top + player->PlayerAnimatedSprite.getGlobalBounds().height / 2);

	Position playerOnArena((int)centerOfPlayerBody.x / BlockSize.x, (int)centerOfPlayerBody.y / BlockSize.y);

	Bomb* bombToAdd = new Bomb(playerOnArena, player->BombPower, player->PlayerId);
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
		player->BombNumber--;
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
			if (PlayerList.at(0)->PlayerId == bomb->Id)
				PlayerList.at(0)->BombNumber++;
			else
				PlayerList.at(1)->BombNumber++;
			
		}
	}
	BombList = listOfBombs;
}

void Manager::ExplodeBomb(Bomb * bomb)
{
	Position bombPosition = bomb->getPosition();
	
	for (int i = 1; i <= bomb->Power; i++)
	{

		Position chceckon(bombPosition.X  + i, bombPosition.Y);
		Block* blockToCheck = GetBlock(chceckon);

		if (blockToCheck->isDestructable == true)
		{
			

			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
			Blocks.remove(blockToCheck);
			Block* blockToAdd = new Block(chceckon);
			Blocks.push_front(blockToAdd);
			break;

		}
		else if (blockToCheck->isDestroyed() == true)
		{
			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
		}
		else
			break;
	}

	for (int i = 1; i <= bomb->Power; i++)
	{
		Position chceckon(bombPosition.X - i, bombPosition.Y);
		Block* blockToCheck = GetBlock(chceckon);

		if (blockToCheck->isDestructable == true)
		{


			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
			Blocks.remove(blockToCheck);
			Block* blockToAdd = new Block(chceckon);
			Blocks.push_front(blockToAdd);
			break;

		}
		else if (blockToCheck->isDestroyed() == true)
		{
			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
		}
		else
			break;
	}

	for (int i = 1; i <= bomb->Power; i++)
	{
		Position chceckon(bombPosition.X , bombPosition.Y + i);
		Block* blockToCheck = GetBlock(chceckon);

		if (blockToCheck->isDestructable == true)
		{


			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
			Blocks.remove(blockToCheck);
			Block* blockToAdd = new Block(chceckon);
			Blocks.push_front(blockToAdd);
			break;

		}
		else if (blockToCheck->isDestroyed() == true)
		{
			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
		}
		else
			break;
	}

	for (int i = 1; i <= bomb->Power; i++)
	{
		Position chceckon(bombPosition.X, bombPosition.Y - i);
		Block* blockToCheck = GetBlock(chceckon);

		if (blockToCheck->isDestructable == true)
		{


			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
			Blocks.remove(blockToCheck);
			Block* blockToAdd = new Block(chceckon);
			Blocks.push_front(blockToAdd);
			break;
		}
		else if (blockToCheck->isDestroyed() == true)
		{
			Fire* fireToAdd = new Fire(GetBlock(chceckon)->getSquarePosition());
			FireList.push_front(fireToAdd);
		}
		else
			break;
	}
	
	Fire* fireToAdd = new Fire(GetBlock(bomb->getPosition())->getSquarePosition());
	FireList.push_front(fireToAdd);

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

		if (PlayerList.at(0)->PlayerAnimatedSprite.getGlobalBounds().intersects(myFire->FireSprite.getGlobalBounds()))
		{
			std::cout << "udied";
		}

	}
	FireList = tempList;

}

void Manager::FirstPlayerHandling()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		PlayerList.at(0)->MoveUp();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(0)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(0)->MoveDown();

		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		PlayerList.at(0)->MoveDown();
		for (Block* block : Blocks)
		{

			if (PlayerList.at(0)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(0)->MoveUp();

		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		PlayerList.at(0)->MoveLeft();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(0)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(0)->MoveRight();

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PlayerList.at(0)->MoveRight();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(0)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(0)->MoveLeft();

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && PlayerList.at(0)->BombNumber != 0)
	{
		PlaceABomb(PlayerList.at(0));
	}
}

void Manager::SecondPlayerHandling()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		PlayerList.at(1)->MoveUp();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(1)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(1)->MoveDown();

		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		PlayerList.at(1)->MoveDown();
		for (Block* block : Blocks)
		{

			if (PlayerList.at(1)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(1)->MoveUp();

		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		PlayerList.at(1)->MoveLeft();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(1)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(1)->MoveRight();

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		PlayerList.at(1)->MoveRight();
		for (Block* block : Blocks)
		{
			if (PlayerList.at(1)->PlayerAnimatedSprite.getGlobalBounds().intersects(block->getGlobalBounds()) && block->isDestructed != true)
				PlayerList.at(1)->MoveLeft();

		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && PlayerList.at(1)->BombNumber != 0)
	{
		PlaceABomb(PlayerList.at(1));
	}
}


