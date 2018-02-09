#pragma once
#include <SFML\Graphics.hpp>
#include "Position.h"

class Bomb 
{
public:
	sf::Sprite BombSprite;

	Bomb(Position bombPosition, int power, int id);

	Position getPosition();
	int Id;
	void BombTimer();
	int BombLifetime;
	int Power;

private:

	const Position PosOnArena;
	const sf::Vector2f PositionOfSprite;
	sf::Texture BombTexture;

};
