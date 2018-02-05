#include "Movable.h"



Movable::Movable()
{
}


Movable::~Movable()
{
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