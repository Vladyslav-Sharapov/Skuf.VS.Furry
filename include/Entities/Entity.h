#pragma once

#include <SFML/Graphics.hpp>

#include "Core/GameTypes.h"

class Entity
{
public:
    explicit Entity(const sf::Texture& texture);
    virtual ~Entity() = default;

    virtual void update(sf::Time time_per_frame) = 0;
    virtual void render(sf::RenderWindow& window) const;

	void move(const sf::Vector2f& offset);
	void set_position(const sf::Vector2f& position);
	void set_direction(const Direction direction) {direction_ = direction;};

    [[nodiscard]]
    virtual sf::FloatRect get_bounds() const;

    [[nodiscard]]
    virtual sf::Vector2f get_position() const;

protected:
    sf::Sprite sprite_;
    Direction direction_;
};
