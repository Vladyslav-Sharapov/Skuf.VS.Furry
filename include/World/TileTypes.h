#pragma once

#include <cstdint>

enum class TileType : std::uint8_t
{
    Empty,
    Floor,
    Wall,
    Hazard
};