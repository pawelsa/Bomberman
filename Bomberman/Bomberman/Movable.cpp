#include "Movable.h"



Movable::Movable()
{
}


Movable::~Movable()
{
}

void Movable::Init()
{

	this->CanMoveDown = true;
	this->CanMoveLeft = true;
	this->CanMoveRight = true;
	this->CanMoveUp = true;
	this->IsMovingRight = false;
	this->IsMovingLeft = false;
	this->IsMovingUp = false;
	this->IsMovingDown = false;
}



void Movable::StartMovingRight()
{
	IsMovingRight = true;
	IsMovingLeft = false;
	IsMovingUp = false;
	IsMovingDown = false;
}

void Movable::StartMovingLeft()
{
	IsMovingRight = false;
	IsMovingLeft = true;
	IsMovingUp = false;
	IsMovingDown = false;
}

void Movable::StartMovingUp()
{
	IsMovingRight = false;
	IsMovingLeft = false;
	IsMovingUp = true;
	IsMovingDown = false;
}

void Movable::StartMovingDown()
{
	IsMovingRight = false;
	IsMovingLeft = false;
	IsMovingUp = false;
	IsMovingDown = true;
}

void Movable::SetCurrentAnimationRight()
{
	this->CurrentAnimation = &WalkingRightAnimation;

}

void Movable::SetCurrentAnimationLeft()
{
	this->CurrentAnimation = &WalkingLeftAnimation;

}

void Movable::SetCurrentAnimationUp()
{
	this->CurrentAnimation = &WalkingUpAnimation;

}

void Movable::SetCurrentAnimationDown()
{
	this->CurrentAnimation = &WalkingDownAnimation;

}