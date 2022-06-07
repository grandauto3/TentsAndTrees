#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <wrl.h>

#include "../core/Definitions.h"

class Grid
{
public:
	Grid(int size);
	Grid(int size, TileType treepos[][GRID_SIZE]);
	~Grid();

	void Update();

	sf::Sprite** GetSpriteArray() const;
	TileType GetTileAtPosition(int x, int y);
	void SwitchTile(sf::Vector2i pos, TileType nextTile);

private:
	Grid() = default;

	//Functions
	void Init(int size);
	bool SetSprites(int size);
	void SetPosition(int size);
	TileType** TranslateGrid(TileType treepos[][GRID_SIZE]);

	//Grid
	TileType** gridArray_ptr = 0;
	sf::Sprite** gridTiles_ptr = 0;
	bool standardNeeded = false;
	bool isFailed = false;
};
