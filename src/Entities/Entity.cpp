#include "Entities/Entity.h"

Entity::Entity(const sf::Texture& texture) :
    sprite_{ texture }
{
}

void Entity::render(sf::RenderWindow& window) const
{
    window.draw(sprite_);
}

void Entity::move(const sf::Vector2f& offset)
{
	sprite_.move(offset);
}

void Entity::set_position(const sf::Vector2f& position)
{
    sprite_.setPosition(position);
}

sf::FloatRect Entity::get_bounds() const
{
    return sprite_.getGlobalBounds();
}

sf::Vector2f Entity::get_position() const
{
    return sprite_.getPosition();
}