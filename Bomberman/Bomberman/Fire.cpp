#include "Fire.h"



Fire::Fire()
{
}

Fire::Fire(sf::Vector2f position)
{
	try
	{
		FireTexture.loadFromFile("Images/Fire.png");
		FireSprite.setTexture(FireTexture);
		FireSprite.setPosition(position);
	}
	catch (const std::exception& ex)
	{
		throw ex;
	}
}


Fire::~Fire()
{
}

void Fire::FireTimer()
{
	FireLifeTime--;
}
