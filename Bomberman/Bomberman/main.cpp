#include "Manager.h"



	sf::RenderWindow window(sf::VideoMode(dim::ScreenDimensions.x, dim::ScreenDimensions.y), "Bomberman");
	sf::Clock frameClock;

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
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				newManager->myPlayer.MoveUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				newManager->myPlayer.MoveDown();

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				newManager->myPlayer.MoveLeft();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				newManager->myPlayer.MoveRight();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {

				//newManager
			}

		}

		window.clear();

		

		newManager->myPlayer.PlayerAnimatedSprite.play(*newManager->myPlayer.CurrentAnimation);
		newManager->myPlayer.PlayerAnimatedSprite.update(frameClock.restart());
		newManager->display();
		window.draw(newManager->myPlayer.PlayerAnimatedSprite);


		window.display();
	}

	return 0;
}