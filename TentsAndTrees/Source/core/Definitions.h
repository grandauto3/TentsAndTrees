#pragma once


#pragma region GameStrings

#define GAME_NAME "Tents and Trees"

#pragma endregion

#pragma region ScreenSizes

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

#pragma endregion

#pragma region GameSize

#define GRID_SIZE 15

#pragma endregion

enum class TileType
{
	None,
	Grass,
	Tree,
	Tent,
	Unknown
};
