#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Definitions.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tents and Trees", sf::Style::Titlebar | sf::Style::Close);

	Game& game = Game::getInstance(&window);

	game.Awake();
	game.Start();

	while(window.isOpen())
	{
		sf::Event event;

		game.Input();
		game.Update();
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			game.ProcessEvents(event);
		}

		window.clear();
		game.Draw();
		window.display();
	}

	return 0;
}
