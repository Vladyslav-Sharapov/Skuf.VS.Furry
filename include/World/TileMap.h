#pragma once

#include "World/Tile.h"

#include <SFML/Graphics.hpp>
#include <vector>

class TileMap
{
public:
    void load(const sf::Texture& tile_set_texture);


    void render(sf::RenderWindow& window) const;

    void set_position(sf::Vector2f position);

private:
    std::vector<Tile> tiles_;

	sf::Vector2f position_;

    static constexpr int kTileSize = 32;
    static constexpr int kMapWidth = 20;
    static constexpr int kMapHeight = 15;
};