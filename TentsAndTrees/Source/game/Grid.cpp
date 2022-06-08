#include "Grid.h"

#include <iostream>
#include <SFML/System/Vector2.hpp>

#include "Tile.h"

void Grid::Init()
{
	IterateOverGrid([this](std::int32_t x, std::int32_t y)
	{
		const std::int32_t index = x + y;

		TileType tmpTileType;
		if (!(index & 1))
			tmpTileType = TileType::Tree;
		else
			tmpTileType = TileType::Unknown;

		grid[x][y] = std::make_unique<Tile>(tmpTileType, sf::Vector2i(x, y));
	}, nullptr);
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	IterateOverGrid([this, &target](std::int32_t x, std::int32_t y)
	{
		target.draw(*grid[x][y]->GetSprite());
	}, nullptr);
}

void Grid::OnTileClicked(const sf::Vector2f& mousePosition) const
{
	IterateOverGrid([this, &mousePosition](std::int32_t x, std::int32_t y)
	{
		const std::unique_ptr<Tile>& currentTile = grid[x][y];
		if (currentTile->GetSprite()->getGlobalBounds().contains(mousePosition))
		{
			//Console Output
			std::cout << "Hit at: X " << x + 1 << " Y " << y + 1 << std::endl;

			switch (currentTile->GetType())
			{
				case TileType::None:
					//Console Output
					std::cout << "None" << std::endl;
					break;
				case TileType::Tree:
					//Console Output
					std::cout << "Tree" << std::endl;
					break;
				case TileType::Grass:

					SwapTile(currentTile, TileType::Tent);

				//Console Output
					std::cout << "Grass" << std::endl;
					break;
				case TileType::Tent:

					SwapTile(currentTile, TileType::Grass);

				//Console Output
					std::cout << "Tent" << std::endl;
					break;
				case TileType::Unknown:

					SwapTile(currentTile, TileType::Grass);

				//Console Output
					std::cout << "Unknown" << std::endl;
					break;
			}
		}
	}, nullptr);
}

void Grid::SwapTile(const std::unique_ptr<Tile>& tile, TileType nextTile) const
{
	tile->SetType(nextTile);
}


void Grid::IterateOverGrid(const IteratorFunction& gridFunction, const IteratorFunction& uiFunction) const
{
	for (std::int32_t x = 0; x < GRID_SIZE; ++x)
	{
		if (uiFunction)
			uiFunction(x, 0);
	}
	for (std::int32_t y = 0; y < GRID_SIZE; ++y)
	{
		if (uiFunction)
			uiFunction(0, y);
	}

	for (std::int32_t x = 1; x < GRID_SIZE; ++x)
	{
		for (std::int32_t y = 1; y < GRID_SIZE; ++y)
		{
			if (gridFunction)
				gridFunction(x, y);
		}
	}
}
