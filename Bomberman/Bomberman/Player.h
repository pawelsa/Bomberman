#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>
#include "AnimatedSprite.hpp"
#include "Movable.h"
#include "Dimensions.h"

class Player : public Movable
{
public:
	Player();
	~Player();

	int Lives;
	bool CanEatGhost;

	virtual void Init() override;


	virtual void Move() override;
	void StopMovingInCurrentDirection();
	void CantMove();
	void CanMove();



	void SetCurrentAnimationDead();


	AnimatedSprite BombermanAnimatedSprite;
	//AnimatedSprite DeadBombermanAnimatedSprite;

	void Restart();

private:
	
	/*
	sf::Texture DeadBombermanSpriteSheet;

	Animation DeadAnimation;*/
};
