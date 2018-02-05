#include "Manager.h"



	sf::RenderWindow window(sf::VideoMode(dim::ScreenDimensions.x, dim::ScreenDimensions.y), "Bomberman");

int main()
{

	Manager *newManager = new Manager();
	

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();




		}

		window.clear();


		newManager->display();


		window.display();
	}

	return 0;
}