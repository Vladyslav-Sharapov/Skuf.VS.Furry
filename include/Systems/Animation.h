#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
public:
    void update(sf::Sprite& sprite, sf::Time time_per_frame);

private:
    std::uint8_t current_frame_ = 0;
    std::uint8_t frame_count_ = 0;
    float frame_time_ = 0.1f;
    float timer_ = 0.f;
};
