#include "World/Tile.h"

#include "World/Tile.h"

Tile::Tile(TileType tile_type, const sf::Texture& texture) :
    type{ tile_type },
    sprite{ texture }
{
    is_solid = type == TileType::Wall || type == TileType::Empty;
}