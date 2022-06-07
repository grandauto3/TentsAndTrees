#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Definitions.h"


class ResourceManager
{
public:
	typedef std::shared_ptr<sf::Texture> TexturePtr;

	static ResourceManager& Get()
	{
		static ResourceManager rm;

		return rm;
	}

	void InitResources() const;

	TexturePtr GetTexture(TileType type);

private:
	struct TexturePaths
	{
		std::string Grass = "Resources/Textures/Tiles/GrassTile.png";
		std::string Tree = "Resources/Textures/Tiles/TreeTile.png";
		std::string Tent = "Resources/Textures/Tiles/TentTile.png";
		std::string Unknown = "Resources/Textures/Tiles/UnknownTile.png";
	} resource_paths;

	ResourceManager();

	//Textures
	TexturePtr grass_texture;
	TexturePtr tree_texture;
	TexturePtr tent_texture;
	TexturePtr unknown_texture;
};
