#include "Player.h"

using namespace std;


Player::Player()
{
	this->Init();
}


Player::~Player()
{
}

void Player::Init()
{
	try
	{

		//this->_sprite.setTexture(this->BombermanSpriteSheet);

		Animation walkingAnimationDown;
		walkingAnimationDown.setSpriteSheet(dim::BombermanTexture);
		walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));

		Animation walkingAnimationLeft;
		walkingAnimationLeft.setSpriteSheet(dim::BombermanTexture);
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));

		Animation walkingAnimationRight;
		walkingAnimationRight.setSpriteSheet(dim::BombermanTexture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));

		Animation walkingAnimationUp;
		walkingAnimationUp.setSpriteSheet(dim::BombermanTexture);
		walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));


		SetCurrentAnimationDown();
		/*
		this->DeadBombermanSpriteSheet.loadFromFile("Images/ghosthere.png");
		this->DeadAnimation.setSpriteSheet(DeadBombermanSpriteSheet);
		DeadAnimation.addFrame(sf::IntRect(51, 1, 15, 14));
		DeadAnimation.addFrame(sf::IntRect(66, 1, 17, 13));
		DeadAnimation.addFrame(sf::IntRect(83, 1, 16, 12));
		DeadAnimation.addFrame(sf::IntRect(99, 1, 16, 12));
		DeadAnimation.addFrame(sf::IntRect(115, 1, 16, 13));
		DeadAnimation.addFrame(sf::IntRect(130, 1, 17, 14));
		DeadAnimation.addFrame(sf::IntRect(147, 1, 15, 15));
		DeadAnimation.addFrame(sf::IntRect(164, 1, 13, 15));
		DeadAnimation.addFrame(sf::IntRect(180, 1, 13, 16));
		DeadAnimation.addFrame(sf::IntRect(197, 1, 14, 16));
		DeadAnimation.addFrame(sf::IntRect(211, 1, 15, 17));
		DeadAnimation.addFrame(sf::IntRect(1, 1, 1, 1));
		*/

		this->CanEatGhost = false;

		this->Lives = 3;
		BombermanAnimatedSprite.setPosition(20, 20);

	}
	catch (const std::exception& ex)
	{
		std::cout << "error occured durning initialization of a player" << ex.what() << endl;
		throw ex;
	}


}



void Player::StopMovingInCurrentDirection()
{
	if (IsMovingRight == true)
	{
		CanMoveRight = false;
		BombermanAnimatedSprite.move(-1, 0);
		IsMovingRight = false;
	}

	else if (IsMovingLeft == true)
	{
		CanMoveLeft = false;
		BombermanAnimatedSprite.move(1, 0);

		IsMovingLeft = true;
	}

	else if (IsMovingUp == true)
	{
		CanMoveUp = false;
		BombermanAnimatedSprite.move(0, 1);

		IsMovingUp = false;
	}

	else if (IsMovingDown == true)
	{
		CanMoveDown = false;
		BombermanAnimatedSprite.move(0, -1);

		IsMovingDown = false;
	}
}

void Player::Move()
{
	if (IsMovingRight == true && CanMoveRight == true)
	{
		Movable::SetCurrentAnimationRight();
		BombermanAnimatedSprite.move(1, 0);
	}
	if (IsMovingLeft == true && CanMoveLeft == true)
	{
		Movable::SetCurrentAnimationLeft();
		BombermanAnimatedSprite.move(-1, 0);
	}
	if (IsMovingUp == true && CanMoveUp == true)
	{
		Movable::SetCurrentAnimationUp();
		BombermanAnimatedSprite.move(0, -1);
	}
	if (IsMovingDown == true && CanMoveDown == true)
	{
		Movable::SetCurrentAnimationDown();
		BombermanAnimatedSprite.move(0, 1);
	}
}




void Player::SetCurrentAnimationDead()
{
	//Movable::CurrentAnimation = &DeadAnimation;
}



void Player::CantMove()
{
	this->CanMoveDown = false;
	this->CanMoveLeft = false;
	this->CanMoveRight = false;
	this->CanMoveUp = false;
}

void Player::CanMove()
{
	this->CanMoveDown = true;
	this->CanMoveLeft = true;
	this->CanMoveRight = true;
	this->CanMoveUp = true;
}

void Player::Restart()
{
	this->SetCurrentAnimationRight();
	this->BombermanAnimatedSprite.setPosition(10, 10);
	this->CanMove();
}