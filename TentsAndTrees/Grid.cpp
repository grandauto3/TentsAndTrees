#include "Grid.h"

Grid::Grid(int size)
{
	Init(size);
}

Grid::Grid(int size, TileState treepos[][GRID_SIZE])
	: gridArray_ptr(TranslateGrid(treepos))
{
	Init(size);
}

Grid::Grid()
{

}

//deletes Array Pointers
Grid::~Grid()
{
	for(int i = 0; i < GRID_SIZE; i++)
	{
		delete[] gridArray_ptr[i];
		delete[] gridTiles_ptr[i];
	}

	delete[] gridArray_ptr;
	delete[] gridTiles_ptr;
}

void Grid::Update() 
{
	if(isFailed) return;

	SetSprites(GRID_SIZE);
	
}


sf::Sprite** Grid::GetSpriteArray()
{
	return gridTiles_ptr;
}

TileState Grid::GetTileAtPosition(int x, int y)
{
	TileState state;

	if((x < GRID_SIZE && x >= 0) && (y < GRID_SIZE && y >= 0))
		state = gridArray_ptr[x][y];
	else
		state = TileState::None;

	return state;
}

void Grid::Init(int size)
{
	//set 1st Dimension of Array
	if(!gridArray_ptr)
	{
		gridArray_ptr = new TileState*[size];
		standardNeeded = true;
	}
	
	gridTiles_ptr = new sf::Sprite*[size];

	//set Default Tiles and 2nd Dimension of Array
	for(int x = 0; x < size; x++)
	{
		if(standardNeeded)
		{
			gridArray_ptr[x] = new TileState[size];
			for (int y = 0; y < size; y++)
				gridArray_ptr[x][y] = TileState::None;
		}

		gridTiles_ptr[x] = new sf::Sprite[size];
	}
	
	#pragma region SetTextures

	//set Textures
	if(grasTexture.loadFromFile(GRAS_TILE_PATH))
		std::cout << "Gras Texture successfully loaded" << std::endl;
	else
		std::cout << "Gras Texture not successfully loaded" << std::endl;

	if(treeTexture.loadFromFile(TREE_TILE_PATH))
		std::cout << "Tree Texture successfully loaded" << std::endl;
	else
		std::cout << "Tree Texture not successfully loaded" << std::endl;

	if(tentTexture.loadFromFile(TENT_TILE_PATH))
		std::cout << "Tent Texture successfully loaded" << std::endl;
	else
		std::cout << "Tent Texture not successfully loaded" << std::endl;

	if(unknownTexture.loadFromFile(UNKNOWN_TILE_PATH))
		std::cout << "Unknown Texture successfully loaded" << std::endl;
	else
		std::cout << "Unknown Texture not successfully loaded" << std::endl;

	#pragma endregion

	isFailed = !SetSprites(size);
	SetPosition(size);
}

bool Grid::SetSprites(int size)
{
	for(int x = 0; x < size; x++)
	{	
		for(int y = 0; y < size; y++)
		{
			switch(gridArray_ptr[x][y])
			{
				case TileState::Gras:
					gridTiles_ptr[x][y].setTexture(grasTexture);
					break;

				case TileState::Tree:
					gridTiles_ptr[x][y].setTexture(treeTexture);
					break;

				case TileState::Tent:
					gridTiles_ptr[x][y].setTexture(tentTexture);
					break;
				case TileState::Unknown:
					gridTiles_ptr[x][y].setTexture(unknownTexture);
					break;
				default:
					gridTiles_ptr[x][y].setTexture(unknownTexture);
					std::cout << "Error: Texture at x:" << x << " y:" << y << " could not be loaded" << std::endl;
					return false;
			}
		}
	}
	return true;
}

void Grid::SetPosition(int size)
{
	sf::Vector2f tempSize = sf::Vector2f(gridTiles_ptr[0][0].getLocalBounds().width, gridTiles_ptr[0][0].getLocalBounds().height);

	sf::Vector2f offset = sf::Vector2f(0.f, 100.f);

	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
		{
			gridTiles_ptr[x][y].setPosition((SCREEN_WIDTH / 10) + (tempSize.x * x) + offset.x, (SCREEN_HEIGHT / 10) + (tempSize.y * y) + offset.y);
		}
	}
}

TileState ** Grid::TranslateGrid(TileState treepos[][GRID_SIZE])
{
	TileState** grid = new TileState*[GRID_SIZE];

	for(int x = 0; x < GRID_SIZE; x++)
	{
		grid[x] = new TileState[GRID_SIZE];
		for(int y = 0; y < GRID_SIZE; y++)
		{
			grid[x][y] = treepos[y][x];
		}
	}

	return grid;
}

void Grid::SwitchTile(sf::Vector2i pos, TileState nextTile)
{

}
