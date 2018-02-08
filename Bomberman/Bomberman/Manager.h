#pragma once
#include "Block.h"
#include "Player.h"
#include <list>
#include "UiManager.h"
#include "Fire.h"

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
	std::list<Fire*> FireList;
	std::list<Bomb*> BombList;
	void Init();
	
	std::list<Block*> GetBlocks();


	sf::Vector2f BlockSize = sf::Vector2f(60, 60);
	sf::Texture BlockTexture;
	

	void PlaceABomb();
	void BombHandling();
	void ExplodeBomb(Bomb* bomb);
	Block* GetBlock(Position position);

	void FireHandling();

};
