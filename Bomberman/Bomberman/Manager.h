#pragma once
#include "Block.h"
#include "Player.h"
#include <list>
#include "UiManager.h"

class Manager 
{
public:

	Manager();
	~Manager();

	void GameLoop();

private:

	UiManager UIM;
	Player* myPlayer;

	std::list<Block*> Blocks;
	std::list<Bomb*> BombList;
	void Init();
	
	std::list<Block*> GetBlocks();
	

	void PlaceABomb();
	void BombHandling();

};
