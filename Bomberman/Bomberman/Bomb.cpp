#include "Bomb.h"

Bomb::Bomb(Position mPosition, int power, int id):PosOnArena(mPosition)
{
	this->BombTexture.loadFromFile("Images/Bomb.png");
	this->BombSprite.setTexture(BombTexture);
	this->Power = power;
	sf::Vector2f BlockSize = sf::Vector2f(60, 60);
	this->Id = id;

	BombSprite.setPosition(sf::Vector2f(PosOnArena.X*BlockSize.x, PosOnArena.Y*BlockSize.y));
	BombLifetime = 200;
}

void Bomb::BombTimer()
{
	BombLifetime--;
}

Position Bomb::getPosition() {

	return PosOnArena;
}
