#include "Game.h"

#include <iostream>

#include "Grid.h"
#include "Tile.h"


/////////////////////////////////////////////////////
//Public:
/////////////////////////////////////////////////////


void Game::Init()
{
	IterateOverGrid([this](std::int32_t x, std::int32_t y)
	{
		const std::int32_t index = x + y;

		TileType tmpTileType;
		if (!(index & 1))
			tmpTileType = TileType::Tree;
		else
			tmpTileType = TileType::Unknown;

		grid[x][y] = std::make_unique<Tile>(tmpTileType, sf::Vector2i(x, y));
	});
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
		IterateOverGrid([this](std::int32_t x, std::int32_t y)
		{
			const std::unique_ptr<Tile>& currentTile = grid[x][y];
			if (currentTile->GetSprite()->getGlobalBounds().contains(
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
			{
				//Console Output
				std::cout << "Hit at: X " << x + 1 << " Y " << y + 1 << std::endl;

				switch (currentTile->GetType())
				{
					case TileType::None:
						//Console Output
						std::cout << "None" << std::endl;
						break;
					case TileType::Tree:
						//Console Output
						std::cout << "Tree" << std::endl;
						break;
					case TileType::Grass:

						SwapTile(sf::Vector2i(x, y), TileType::Tent);

					//Console Output
						std::cout << "Grass" << std::endl;
						break;
					case TileType::Tent:

						SwapTile(sf::Vector2i(x, y), TileType::Grass);

					//Console Output
						std::cout << "Tent" << std::endl;
						break;
					case TileType::Unknown:

						SwapTile(sf::Vector2i(x, y), TileType::Grass);

					//Console Output
						std::cout << "Unknown" << std::endl;
						break;
					default:
						break;
				}
			}
		});
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
	IterateOverGrid([this](std::int32_t x, std::int32_t y)
	{
		window->draw(*grid[x][y]->GetSprite());
	});
}

Game::~Game()
{
}

/////////////////////////////////////////////////////
//Private:
/////////////////////////////////////////////////////

void Game::SwapTile(sf::Vector2i pos, TileType nextTile)
{
}

void Game::IterateOverGrid(const IteratorFunction& inFunction) const
{
	for (std::int32_t x = 0; x < GRID_SIZE; ++x)
	{
		for (std::int32_t y = 0; y < GRID_SIZE; ++y)
		{
			inFunction(x, y);
		}
	}
}
