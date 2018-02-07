#include "Bomb.h"

Bomb::Bomb(sf::Vector2f mPosition):position(mPosition) 
{
	this->BombTexture.loadFromFile("Images/Bomberman.png", sf::IntRect(84, 21, 14, 16));
	this->BombSprite.setTexture(BombTexture);

	BombSprite.setPosition(mPosition);
	BombLifetime = 300;
}

void Bomb::BombTimer()
{
	BombLifetime--;
}
