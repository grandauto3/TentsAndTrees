#pragma once

#include <array>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "../core/Definitions.h"

class Grid;

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
	void SwapTile(sf::Vector2i pos, TileType nextTile);

	typedef std::function<void(std::int32_t, std::int32_t)> IteratorFunction;

	void IterateOverGrid(const IteratorFunction& inFunction) const;

	std::array<std::array<std::unique_ptr<Tile>, GRID_SIZE>, GRID_SIZE> grid = {};


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
