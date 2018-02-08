#pragma once
#include "SFML\Graphics.hpp"
class Fire
{
public:
	Fire();
	Fire(sf::Vector2f position);


	~Fire();
	int FireLifeTime = 60;
	void FireTimer();
	sf::Sprite FireSprite;

private:
	sf::Texture FireTexture;
};

