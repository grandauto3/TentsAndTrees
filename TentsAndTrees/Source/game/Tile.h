#pragma once
#include <SFML/System/Vector2.hpp>
#include "../core/ResourceManager.h"

enum class TileType;

class Tile
{
public:
	Tile(TileType inType, sf::Vector2i inPosition);

	[[nodiscard]]
	std::unique_ptr<sf::Sprite>& GetSprite()
	{
		return sprite;
	}

	[[nodiscard]]
	TileType GetType() const
	{
		return type;
	}

	void SetType(TileType inType)
	{
		type = inType;
	}

private:
	TileType type;
	std::unique_ptr<sf::Sprite> sprite;
};
