#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include <list>
#include "Block.h"


class UiManager
{
public:
	UiManager();
	~UiManager();
	sf::Clock frameClock;

	sf::Vector2i ScreenDimensions = sf::Vector2i(1280, 720);

	sf::RenderWindow* window;

	void DrawBlocks(std::list<Block*> blocks);
	void DrawPlayer(Player* player);
	void DrawBombs(std::list<Bomb*> bombs);
};

