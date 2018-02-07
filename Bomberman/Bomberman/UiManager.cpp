#include "UiManager.h"



UiManager::UiManager()
{
	this->window = new sf::RenderWindow(sf::VideoMode(ScreenDimensions.x, ScreenDimensions.y), "Bomberman");
}


UiManager::~UiManager()
{
}

void UiManager::DrawBlocks(std::vector<Block*> blocks)
{
	for (Block* block : blocks)
	{		
		window->draw(block->Square);
	}
}

void UiManager::DrawPlayer(Player * player)
{
	window->draw(player->PlayerAnimatedSprite);
	player->PlayerAnimatedSprite.play(*player->CurrentAnimation);
	player->PlayerAnimatedSprite.update(frameClock.restart());
}
