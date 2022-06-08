#pragma once

#include "Grid.h"
#include <SFML/Graphics.hpp>

#include "../core/Definitions.h"


class Game
{
	typedef std::unique_ptr<sf::RenderWindow> WindowPtr;

public:
	Game(WindowPtr& rwindow)
		: window(rwindow)
	{
	}

	~Game();

	Game() = delete;
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game& rhs) = delete;
	Game& operator=(Game&& rhs) = delete;


	void Init();
	void Start();
	void Input();
	void Update();
	void ProcessEvents(sf::Event event);
	void Draw() const;


private:
	std::unique_ptr<Grid> grid;
	WindowPtr& window;
	sf::RectangleShape background;

	bool prevMouseButton = false;

	TileType gridLayout[GRID_SIZE][GRID_SIZE] =
	{
		/////////////////////////////////////////////////////
		//1-3
		/////////////////////////////////////////////////////
		//1
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//2
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//3
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},

		/////////////////////////////////////////////////////
		//4-6
		/////////////////////////////////////////////////////
		//4
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//5
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//6
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},

		/////////////////////////////////////////////////////
		//7-9
		/////////////////////////////////////////////////////
		//7
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//8
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//9
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},

		/////////////////////////////////////////////////////
		//10-12
		/////////////////////////////////////////////////////
		//10
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//11
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//12
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},

		/////////////////////////////////////////////////////
		//13-15
		/////////////////////////////////////////////////////
		//13
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//14
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		},
		//15
		{
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown,
			TileType::Tree, TileType::Unknown, TileType::Tree,
			TileType::Unknown, TileType::Tree, TileType::Unknown
		}
	};
};
