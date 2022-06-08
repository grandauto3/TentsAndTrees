#include "Tile.h"


Tile::Tile(TileType inType, const sf::Vector2i& inPosition)
	: type(inType),
	  sprite(std::make_unique<sf::Sprite>(*ResourceManager::Get().GetTexture(type)))
{
	sf::FloatRect localBounds = sprite->getLocalBounds();
	sf::Vector2f spriteSize = sf::Vector2f(localBounds.width, localBounds.height);

	const sf::Vector2f offset(.0f, 10.f);

	sf::Vector2f tmpPosition = sf::Vector2f(
		(SCREEN_WIDTH / 10) + spriteSize.x * static_cast<float>(inPosition.x) + offset.x,
		(SCREEN_WIDTH / 10) + spriteSize.y * static_cast<float>(inPosition.y) + offset.y);

	sprite->setPosition(tmpPosition);
}

void Tile::UpdateSprite(TileType newType) const
{
	sprite->setTexture(*ResourceManager::Get().GetTexture(newType));
}
