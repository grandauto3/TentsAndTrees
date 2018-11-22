#pragma once

#pragma region ResourcePaths

#define GRAS_TILE_PATH "Resources/res/Tiles/GrasTile.png"
#define TREE_TILE_PATH "Resources/res/Tiles/TreeTile.png"
#define TENT_TILE_PATH "Resources/res/Tiles/TentTile.png"
#define UNKNOWN_TILE_PATH "Resources/res/Tiles/UnknownTile.png"

#pragma endregion

#pragma region ScreenSizes

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

#pragma endregion

#pragma region GameSize

#define GRID_SIZE 15

#pragma endregion

enum class TileState 
{
	None,
	Tree,
	Gras,
	Tent,
	Unknown
};
