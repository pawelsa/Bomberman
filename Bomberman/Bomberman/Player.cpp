#include "Player.h"


Player::Player()
{
	Init();
}


Player::~Player()
{
}

void Player::MoveRight()
{
	SetCurrentAnimationRight();
	PlayerAnimatedSprite.move(Speed,0);
}

void Player::MoveLeft()
{
	SetCurrentAnimationLeft();
	PlayerAnimatedSprite.move(-Speed, 0);

}

void Player::MoveUp()
{
	SetCurrentAnimationUp();
	PlayerAnimatedSprite.move(0, -Speed);

}

void Player::MoveDown()
{
	SetCurrentAnimationDown();
	PlayerAnimatedSprite.move(0, Speed);
}


void Player::Init()
{
	this->Texture.loadFromFile("Images/Bomberman.png");

	WalkingDownAnimation.setSpriteSheet(Texture);
	WalkingDownAnimation.addFrame(sf::IntRect(2, 3, 12, 16));
	WalkingDownAnimation.addFrame(sf::IntRect(16, 3, 12, 16));
	WalkingDownAnimation.addFrame(sf::IntRect(30, 3, 12, 16));


	WalkingLeftAnimation.setSpriteSheet(Texture);
	WalkingLeftAnimation.addFrame(sf::IntRect(43, 21, 11, 16));
	WalkingLeftAnimation.addFrame(sf::IntRect(56, 21, 12, 16));
	WalkingLeftAnimation.addFrame(sf::IntRect(70, 21, 11, 16));

	WalkingRightAnimation.setSpriteSheet(Texture);
	WalkingRightAnimation.addFrame(sf::IntRect(43, 3, 11, 16));
	WalkingRightAnimation.addFrame(sf::IntRect(56, 3, 11, 16));
	WalkingRightAnimation.addFrame(sf::IntRect(70, 3, 11, 16));

	WalkingUpAnimation.setSpriteSheet(Texture);
	WalkingUpAnimation.addFrame(sf::IntRect(2, 21, 12, 16));
	WalkingUpAnimation.addFrame(sf::IntRect(16, 21, 12, 16));
	WalkingUpAnimation.addFrame(sf::IntRect(30, 21, 12, 16));

	SetCurrentAnimationDown();
	PlayerAnimatedSprite.setPosition(100, 100);

}
