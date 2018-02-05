#pragma once

#include "GameObject.h"
#include "Animation.hpp"

class Movable :public GameObject {

public:
	Movable();
	~Movable();

	virtual void Init() override;

	bool CanMoveRight;
	bool CanMoveLeft;
	bool CanMoveUp;
	bool CanMoveDown;

	bool IsMovingRight;
	bool IsMovingLeft;
	bool IsMovingUp;
	bool IsMovingDown;

	void StartMovingRight();
	void StartMovingLeft();
	void StartMovingUp();
	void StartMovingDown();
	virtual void StopMovingInCurrentDirection() = 0;
	virtual void Move() = 0;

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
