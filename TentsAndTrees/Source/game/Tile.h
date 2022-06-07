#pragma once
#include <SFML/System/Vector2.hpp>
#include "../core/ResourceManager.h"

enum class TileType;

class Tile
{
public:
	explicit Tile(TileType inType)
		: type(inType)
	{
	}

	[[nodiscard]]
	ResourceManager::TexturePtr GetTexture() const;

	[[nodiscard]]
	TileType GetType() const
	{
		return type;
	}

	void SetType(TileType inType)
	{
		type = inType;
	}

	[[nodiscard]]
	sf::Vector2i GetPosition() const
	{
		return position;
	}

private:
	sf::Vector2i position;
	TileType type;
};
