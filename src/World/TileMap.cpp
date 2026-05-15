#include "World/TileMap.h"

void TileMap::load(const sf::Texture& tile_set_texture)
{
    tiles_.clear();

    for (int row = 0; row < kMapHeight; ++row)
    {
        for (int col = 0; col < kMapWidth; ++col)
        {
            Tile tile{
                TileType::Floor,
                tile_set_texture
            };

            tile.sprite.setPosition({
                position_.x + static_cast<float>(col * kTileSize),
                position_.y + static_cast<float>(row * kTileSize)
                });

            tiles_.push_back(tile);
        }
    }
}

void TileMap::render(sf::RenderWindow& window) const
{
    for (const Tile& tile : tiles_)
    {
        window.draw(tile.sprite);
    }
}

void TileMap::set_position(sf::Vector2f position)
{
	position_ = position;
}
