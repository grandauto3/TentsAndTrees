#pragma once
#include <array>
#include <functional>
#include <memory>
#include <SFML/Graphics/Drawable.hpp>

#include "../core/Definitions.h"

class Tile;

class Grid : public sf::Drawable
{
public:
	void Init();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void OnTileClicked(const sf::Vector2f& mousePosition) const;

private:
	typedef std::function<void(std::int32_t, std::int32_t)> IteratorFunction;

	void IterateOverGrid(const IteratorFunction& gridFunction, const IteratorFunction& uiFunction) const;

	void SwapTile(const std::unique_ptr<Tile>& tile, TileType nextTile) const;

	std::array<std::array<std::unique_ptr<Tile>, GRID_SIZE>, GRID_SIZE> grid = {};
};
