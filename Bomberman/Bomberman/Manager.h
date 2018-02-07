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
	
	void plantBomb();
	


private:

	UiManager UIM;

	sf::Texture BlockTexture;

	sf::Vector2f BlockSize = sf::Vector2f(60, 60);

	Player* myPlayer;
	std::vector<Block*> Blocks;
	void Init();
	
	std::vector<Block*> GetBlocks();
	
	bool collision();


};
