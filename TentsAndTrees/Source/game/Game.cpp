#include "Game.h"
#include "Grid.h"


/////////////////////////////////////////////////////
//Public:
/////////////////////////////////////////////////////


void Game::Init()
{
	grid = std::make_unique<Grid>(GRID_SIZE, gridLayout);
	gridSprite_ptr = grid->GetSpriteArray();
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
		for (int x = 0; x < GRID_SIZE; x++)
		{
			for (int y = 0; y < GRID_SIZE; y++)
			{
				if (gridSprite_ptr[x][y].getGlobalBounds().contains(
					static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window))))
				{
					//Console Output
					std::cout << "Hit at: X " << x + 1 << " Y" << y + 1 << std::endl;

					TileType state = grid->GetTileAtPosition(x, y);
					switch (state)
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
							std::cout << "Unkown" << std::endl;
							break;
						default:
							break;
					}
				}
			}
		}
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
	//Update Grid
	grid->Update();
	gridSprite_ptr = grid->GetSpriteArray();
}

void Game::ProcessEvents(sf::Event e)
{
}

void Game::Draw()
{
	//Background
	window->draw(background);

	//Grid
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			window->draw(gridSprite_ptr[x][y]);
		}
	}
}

Game::~Game()
{
}

/////////////////////////////////////////////////////
//Private:
/////////////////////////////////////////////////////

void Game::SwapTile(sf::Vector2i pos, TileType nextTile)
{
	grid->SwitchTile(pos, nextTile);
}
