#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <wrl.h>

#include "Definitions.h"

class Grid
{
public:

	Grid(int size);
	Grid(int size, TileState treepos[][GRID_SIZE]);
	~Grid();

	void Update();

	sf::Sprite** GetSpriteArray();
	TileState GetTileAtPosition(int x, int y);
	void SwitchTile(sf::Vector2i pos, TileState nextTile);

private:

	Grid();



	//Functions
	void Init(int size);
	bool SetSprites(int size);
	void SetPosition(int size);
	TileState** TranslateGrid(TileState treepos[][GRID_SIZE]);

	//Grid
	TileState** gridArray_ptr = 0;
	sf::Sprite** gridTiles_ptr = 0;
	bool standardNeeded = false;
	bool isFailed = false;

	//Textures
	sf::Texture grasTexture;
	sf::Texture treeTexture;
	sf::Texture tentTexture;
	sf::Texture unknownTexture;

};

