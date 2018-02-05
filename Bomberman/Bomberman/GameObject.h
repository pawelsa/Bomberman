#pragma once
#include <SFML\Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

protected:
	virtual void Init();

};