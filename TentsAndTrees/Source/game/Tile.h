#pragma once
#include <SFML/System/Vector2.hpp>
#include "../core/ResourceManager.h"

enum class TileType;

class Tile
{
public:
	Tile(TileType inType, const sf::Vector2i& inPosition);

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
		UpdateSprite(inType);
	}

private:
	TileType type = TileType::None;
	std::unique_ptr<sf::Sprite> sprite = nullptr;
	void UpdateSprite(TileType newType) const;
};
