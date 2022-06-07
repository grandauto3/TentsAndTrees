#include "App.h"
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "ResourceManager.h"

void App::Run()
{
	InitApp();
	StartApp();

	while (window->isOpen())
	{
		UpdateApp();
		sf::Event e{};
		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window->close();

			game->ProcessEvents(e);
		}
		RenderApp();
	}
}

void App::InitApp()
{
	ResourceManager::Get().InitResources();
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tents and Trees",
	                                            sf::Style::Close);

	game = std::make_unique<Game>(window);
	game->Init();
}

void App::StartApp() const
{
	game->Start();
}

void App::UpdateApp() const
{
	game->Input();
	game->Update();
}

void App::RenderApp() const
{
	window->clear();
	game->Draw();
	window->display();
}
