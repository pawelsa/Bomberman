#include "Bomb.h"

Bomb::Bomb(Position mPosition):PosOnArena(mPosition)
{
	this->BombTexture.loadFromFile("Images/Bomberman.png", sf::IntRect(84, 21, 14, 16));
	this->BombSprite.setTexture(BombTexture);

	sf::Vector2f BlockSize = sf::Vector2f(60, 60);


	BombSprite.setPosition(sf::Vector2f(PosOnArena.X*BlockSize.x, PosOnArena.Y*BlockSize.y));
	BombLifetime = 300;
}

void Bomb::BombTimer()
{
	BombLifetime--;
}

Position Bomb::getPosition() {

	return PosOnArena;
}
