#pragma once
#include "Movable.h"
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Bomb.h"
#include <time.h>

extern sf::RenderWindow window;


class Player :
	public Movable
{
public:
	Player();
	~Player();
	
	int BombNumber;
	int BombPower;

	
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	AnimatedSprite PlayerAnimatedSprite;


private:


	void Init();
	int Speed = 5;
	sf::Texture Texture;
};

