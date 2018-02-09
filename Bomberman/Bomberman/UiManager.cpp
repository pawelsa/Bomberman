#include "UiManager.h"



UiManager::UiManager()
{
}


UiManager::~UiManager()
{
	delete this->window;
}

void UiManager::DrawBlocks(std::list<Block*> blocks)
{
	for (Block* block : blocks)
	{		
		window->draw(block->Square);
	}
}

void UiManager::DrawPlayers(std::vector<Player*> PlayerList)
{
	for (Player* player : PlayerList)
	{
		window->draw(player->PlayerAnimatedSprite);
		player->PlayerAnimatedSprite.play(*player->CurrentAnimation);
		player->PlayerAnimatedSprite.update(frameClock.restart());
	}
	
}

void UiManager::DrawBombs(std::list<Bomb*> bombs)
{
	for (Bomb* bomb : bombs)
	{
		window->draw(bomb->BombSprite);
	}
}

void UiManager::DrawFire(std::list<Fire*> fire)
{
	for (Fire* myFire : fire)
	{
		window->draw(myFire->FireSprite);
	}
}

void UiManager::CreateWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(ScreenDimensions.x, ScreenDimensions.y), "Bomberman");
	this->window->setFramerateLimit(60);
}
