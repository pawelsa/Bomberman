#pragma once
#include "Movable.h"
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <time.h>

extern sf::RenderWindow window;


class Player :
	public Movable
{
public:
	Player();
	~Player();
	
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	AnimatedSprite PlayerAnimatedSprite;


private:


	void Init();
	int Speed = 1;
	sf::Texture Texture;
};

