#pragma once

#include "World/TileTypes.h"

#include <SFML/Graphics.hpp>

struct Tile
{
    Tile(TileType tile_type, const sf::Texture& texture);

    TileType type = TileType::Empty;

    sf::Sprite sprite;
	sf::IntRect sprite_rect;

    bool is_solid = false;
};