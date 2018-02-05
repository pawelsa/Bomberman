#pragma once


#include "Animation.hpp"

class Movable
{

public:
	Movable();
	~Movable();

	virtual void Init() = 0;

	
	void SetCurrentAnimationRight();
	void SetCurrentAnimationLeft();
	void SetCurrentAnimationUp();
	void SetCurrentAnimationDown();

	Animation* CurrentAnimation;

	Animation WalkingDownAnimation;
	Animation WalkingUpAnimation;
	Animation WalkingLeftAnimation;
	Animation WalkingRightAnimation;
};
