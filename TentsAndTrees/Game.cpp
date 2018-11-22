#include "Game.h"


/////////////////////////////////////////////////////
//Public:
/////////////////////////////////////////////////////

Game& Game::getInstance(sf::RenderWindow* rwindow)
{
	static Game g(rwindow);
	return g;
}


void Game::Awake()
{
	grid = new Grid(GRID_SIZE, gridLayout);
	gridSprite_ptr = grid->GetSpriteArray();
}

void Game::Start()
{
	//Background
	background.setSize(sf::Vector2f(rwindow->getSize()));
	background.setFillColor(sf::Color::White);
}

void Game::Input()
{
	bool currMouseButton = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	/////////////////////////////////////////////////////
	//Mouse DOWN
	/////////////////////////////////////////////////////
	if(currMouseButton && !prevMouseButton)
	{

		for(int x = 0; x < GRID_SIZE; x++)
		{
			for(int y = 0; y < GRID_SIZE; y++)
			{
				if(gridSprite_ptr[x][y].getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*rwindow)))
				{
					//Console Output
					std::cout << "Hit at: X " << x + 1 << " Y" << y + 1 << std::endl;

					TileState state = grid->GetTileAtPosition(x, y);
					switch(state)
					{
					case TileState::None:
						//Console Output
						std::cout << "None" << std::endl;
						break;
					case TileState::Tree:
						//Console Output
						std::cout << "Tree" << std::endl;
						break;
					case TileState::Gras:

						SwapTile(sf::Vector2i(x, y), TileState::Tent);

						//Console Output
						std::cout << "Gras" << std::endl;
						break;
					case TileState::Tent:

						SwapTile(sf::Vector2i(x, y), TileState::Gras);

						//Console Output
						std::cout << "Tent" << std::endl;
						break;
					case TileState::Unknown:

						SwapTile(sf::Vector2i(x, y), TileState::Gras);

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
	if(currMouseButton && prevMouseButton)
	{ 

	}

	/////////////////////////////////////////////////////
	//Mouse UP
	/////////////////////////////////////////////////////
	if(!currMouseButton && prevMouseButton)
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

void Game::ProcessEvents(sf::Event event)
{

}

void Game::Draw()
{
	//Background
	rwindow->draw(background);

	//Grid
	for(int x = 0; x < GRID_SIZE; x++)
	{
		for(int y = 0; y < GRID_SIZE; y++)
		{
			rwindow->draw(gridSprite_ptr[x][y]);
		}
	}
}


Game::~Game()
{ }

/////////////////////////////////////////////////////
//Private:
/////////////////////////////////////////////////////

Game::Game(sf::RenderWindow* rwindow)
	: rwindow (rwindow)
{ }

void Game::SwapTile(sf::Vector2i pos, TileState nextTile)
{
	grid->SwitchTile(pos, nextTile);
}
