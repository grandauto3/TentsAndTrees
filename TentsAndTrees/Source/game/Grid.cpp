#include "Grid.h"
#include "../core/ResourceManager.h"

Grid::Grid(int size)
{
	Init(size);
}

Grid::Grid(int size, TileType treepos[][GRID_SIZE])
	: gridArray_ptr(TranslateGrid(treepos))
{
	Init(size);
}


//deletes Array Pointers
Grid::~Grid()
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		delete[] gridArray_ptr[i];
		delete[] gridTiles_ptr[i];
	}

	delete[] gridArray_ptr;
	delete[] gridTiles_ptr;
}

void Grid::Update()
{
	if (isFailed)
		return;

	SetSprites(GRID_SIZE);
}


sf::Sprite** Grid::GetSpriteArray() const
{
	return gridTiles_ptr;
}

TileType Grid::GetTileAtPosition(int x, int y)
{
	TileType state;

	if ((x < GRID_SIZE && x >= 0) && (y < GRID_SIZE && y >= 0))
		state = gridArray_ptr[x][y];
	else
		state = TileType::None;

	return state;
}

void Grid::Init(int size)
{
	//set 1st Dimension of Array
	if (!gridArray_ptr)
	{
		gridArray_ptr = new TileType*[size];
		standardNeeded = true;
	}

	gridTiles_ptr = new sf::Sprite*[size];

	//set Default Tiles and 2nd Dimension of Array
	for (int x = 0; x < size; x++)
	{
		if (standardNeeded)
		{
			gridArray_ptr[x] = new TileType[size];
			for (int y = 0; y < size; y++)
				gridArray_ptr[x][y] = TileType::None;
		}

		gridTiles_ptr[x] = new sf::Sprite[size];
	}


	isFailed = !SetSprites(size);
	SetPosition(size);
}

bool Grid::SetSprites(int size)
{
	ResourceManager& rm = ResourceManager::Get();

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			TileType tmp_tile = gridArray_ptr[x][y];


			if (tmp_tile == TileType::None)
			{
				std::cout << "Current Tile not supported" << std::endl;
				return false;
			}

			gridTiles_ptr[x][y].setTexture(*rm.GetTexture(tmp_tile));
		}
	}
	return true;
}

void Grid::SetPosition(int size)
{
	sf::Vector2f tempSize = sf::Vector2f(gridTiles_ptr[0][0].getLocalBounds().width,
	                                     gridTiles_ptr[0][0].getLocalBounds().height);

	sf::Vector2f offset = sf::Vector2f(0.f, 100.f);

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			gridTiles_ptr[x][y].setPosition((SCREEN_WIDTH / 10) + (tempSize.x * x) + offset.x,
			                                (SCREEN_HEIGHT / 10) + (tempSize.y * y) + offset.y);
		}
	}
}

TileType** Grid::TranslateGrid(TileType treepos[][GRID_SIZE])
{
	TileType** grid = new TileType*[GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		grid[x] = new TileType[GRID_SIZE];
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			grid[x][y] = treepos[y][x];
		}
	}

	return grid;
}

void Grid::SwitchTile(sf::Vector2i pos, TileType nextTile)
{
}
