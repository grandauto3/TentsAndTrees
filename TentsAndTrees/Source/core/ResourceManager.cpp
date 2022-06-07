#include "ResourceManager.h"

#include <iostream>

#include <SFML/Graphics.hpp>

void ResourceManager::InitResources() const
{
	//set Textures
	if (grass_texture->loadFromFile(resource_paths.Grass))
		std::cout << "Grass Texture successfully loaded" << std::endl;
	else
		std::cout << "Gras Texture not successfully loaded" << std::endl;

	if (tree_texture->loadFromFile(resource_paths.Tree))
		std::cout << "Tree Texture successfully loaded" << std::endl;
	else
		std::cout << "Tree Texture not successfully loaded" << std::endl;

	if (tent_texture->loadFromFile(resource_paths.Tent))
		std::cout << "Tent Texture successfully loaded" << std::endl;
	else
		std::cout << "Tent Texture not successfully loaded" << std::endl;

	if (unknown_texture->loadFromFile(resource_paths.Tent))
		std::cout << "Unknown Texture successfully loaded" << std::endl;
	else
		std::cout << "Unknown Texture not successfully loaded" << std::endl;
}

ResourceManager::TexturePtr ResourceManager::GetTexture(TileType type)
{
	switch (type)
	{
		case TileType::Grass:
			return grass_texture;
		case TileType::Tree:
			return tree_texture;
		case TileType::Tent:
			return tent_texture;

		case TileType::None:
		case TileType::Unknown:
		default:
			return unknown_texture;
	}
}
