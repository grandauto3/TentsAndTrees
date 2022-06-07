#include "ResourceManager.h"

#include <functional>
#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

void ResourceManager::InitResources() const
{
	std::function debugString = [](const std::string& inName, bool successful) -> std::string
	{
		std::stringstream ss;

		ss << inName << " Texture" << (successful ? "" : " not") << " successfully loaded";

		return ss.str();
	};

	//set Textures
	if (grass_texture->loadFromFile(resource_paths.Grass))
		std::cout << debugString("Grass", true) << std::endl;
	else
		std::cout << debugString("Grass", false) << std::endl;

	if (tree_texture->loadFromFile(resource_paths.Tree))
		std::cout << debugString("Tree", true) << std::endl;
	else
		std::cout << debugString("Tree", false) << std::endl;

	if (tent_texture->loadFromFile(resource_paths.Tent))
		std::cout << debugString("Tent", true) << std::endl;
	else
		std::cout << debugString("Tent", false) << std::endl;

	if (unknown_texture->loadFromFile(resource_paths.Unknown))
		std::cout << debugString("Unknown", true) << std::endl;
	else
		std::cout << debugString("Unknown", false) << std::endl;
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

ResourceManager::ResourceManager()
{
	grass_texture = std::make_shared<sf::Texture>();
	tree_texture = std::make_shared<sf::Texture>();
	tent_texture = std::make_shared<sf::Texture>();
	unknown_texture = std::make_shared<sf::Texture>();
}
