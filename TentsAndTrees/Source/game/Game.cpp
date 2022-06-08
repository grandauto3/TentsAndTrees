#include "Game.h"

#include <iostream>

#include "Grid.h"
#include "Tile.h"


/////////////////////////////////////////////////////
//Public:
/////////////////////////////////////////////////////


void Game::Init()
{
	grid = std::make_unique<Grid>();
	grid->Init();
}

void Game::Start()
{
	//Background
	background.setSize(sf::Vector2f(window->getSize()));
	background.setFillColor(sf::Color::White);
}

void Game::Input()
{
	bool currMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	/////////////////////////////////////////////////////
	//Mouse DOWN
	/////////////////////////////////////////////////////
	if (currMouseButton && !prevMouseButton)
	{
		grid->OnTileClicked(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
	}

	/////////////////////////////////////////////////////
	//Mouse PRESSED
	/////////////////////////////////////////////////////
	if (currMouseButton && prevMouseButton)
	{
	}

	/////////////////////////////////////////////////////
	//Mouse UP
	/////////////////////////////////////////////////////
	if (!currMouseButton && prevMouseButton)
	{
	}

	//Resets MouseButton
	prevMouseButton = currMouseButton;
}

void Game::Update()
{
}

void Game::ProcessEvents(sf::Event e)
{
}

void Game::Draw() const
{
	//Background
	window->draw(background);

	//Grid
	window->draw(*grid);
}

Game::~Game()
{
}

/////////////////////////////////////////////////////
//Private:
/////////////////////////////////////////////////////
