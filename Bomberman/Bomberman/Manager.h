#pragma once
#include "Block.h"
#include "Player.h"
#include <list>
#include "UiManager.h"
#include "SoftBlock.h"
#include "HardBlock.h"
#include "Fire.h"

class Manager 
{
public:

	Manager();
	~Manager();

	bool GameLoop();
	bool InitIntro();
	void ErrorPopOut(const std::exception& ex);
	void InitEndGameWindow();

private:

	UiManager UIM;

	void CheckPlayersAndFire();
	
	std::vector<Player*> PlayerList;
	std::list<Block*> Blocks;
	std::list<Fire*> FireList;
	std::list<Bomb*> BombList;
	void Init();
	
	std::list<Block*> GetBlocks();


	sf::Vector2f BlockSize = sf::Vector2f(60, 60);
	sf::Texture BlockTexture;
	

	void PlaceABomb(Player* player);
	void BombHandling();
	void ExplodeBomb(Bomb* bomb);
	Block* GetBlock(Position position);

	void FireHandling();

	void FirstPlayerHandling();
	void SecondPlayerHandling();

};
