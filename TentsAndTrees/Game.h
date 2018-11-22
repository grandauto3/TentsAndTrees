#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Grid.h"

class Game
{
public:
	//Singleton
	static Game& getInstance(sf::RenderWindow* rwindow);

	void Awake();
	void Start();
	void Input();
	void Update();
	void ProcessEvents(sf::Event event);
	void Draw();

	~Game();

private:
	Game(sf::RenderWindow* rwindow);
	void SwapTile(sf::Vector2i pos, TileState nextTile);

	Grid* grid;

	sf::RenderWindow* rwindow;
	sf::RectangleShape background;
	sf::Sprite** gridSprite_ptr;

	bool prevMouseButton = false;

	TileState gridLayout[GRID_SIZE][GRID_SIZE] =
	{
		/////////////////////////////////////////////////////
		//1-3
		/////////////////////////////////////////////////////
		//1
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//2
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//3
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		
		/////////////////////////////////////////////////////
		//4-6
		/////////////////////////////////////////////////////
		//4
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//5
		{
			TileState::Unknown, TileState::Tree,TileState::Unknown, 
			TileState::Tree,TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree,TileState::Unknown, 
			TileState::Tree,TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree,TileState::Unknown},
		//6
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},

		/////////////////////////////////////////////////////
		//7-9
		/////////////////////////////////////////////////////
		//7
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//8
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//9
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},

		/////////////////////////////////////////////////////
		//10-12
		/////////////////////////////////////////////////////
		//10
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//11
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown,
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//12
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		
		/////////////////////////////////////////////////////
		//13-15
		/////////////////////////////////////////////////////
		//13
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//14
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		},
		//15
		{
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown, 
			TileState::Tree, TileState::Unknown, TileState::Tree,
			TileState::Unknown, TileState::Tree, TileState::Unknown
		}
	};
};

