#pragma once
#include <SFML\Graphics.hpp>
#include "Position.h"

class Bomb 
{
public:
	sf::Sprite BombSprite;

	Bomb(Position bombPosition);

	Position getPosition();

	void BombTimer();
	int BombLifetime;


private:

	const Position PosOnArena;
	const sf::Vector2f PositionOfSprite;
	sf::Texture BombTexture;

};
