#include "Tile.h"


ResourceManager::TexturePtr Tile::GetTexture() const
{
	return ResourceManager::Get().GetTexture(type);
}
