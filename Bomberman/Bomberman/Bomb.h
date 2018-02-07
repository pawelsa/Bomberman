#pragma once
#include "SFML\Graphics.hpp"

class Bomb 
{
public:
	sf::Sprite BombSprite;

	Bomb(sf::Vector2f bombPosition);

	void BombTimer();
	int BombLifetime;


private:
	const sf::Vector2f position;
	sf::Texture BombTexture;

};
