#include "Entities/Player.h"

Player::Player(const sf::Texture& texture) :
    Entity(texture)
{
	setup_sprite();

    speed_ = 100.0f; // Set the player's speed
}

void Player::update(sf::Time time_per_frame)
{
	key_handler(time_per_frame);
}

void Player::render(sf::RenderWindow& window) const
{
        window.draw(sprite_);
}

void Player::setup_sprite()
{
    sprite_.setTextureRect(sf::IntRect{ sf::Vector2i{0,0}, sf::Vector2i{64,64} });
    sprite_.setPosition(sf::Vector2f(400.f, 300.f)); // Start the player in the center of the window
}

void Player::key_handler(sf::Time time_per_frame)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        direction_ = Direction::Up;
        move({ 0.f, -speed_ * time_per_frame.asSeconds() });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        direction_ = Direction::Down;
        move({ 0.f, speed_ * time_per_frame.asSeconds() });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        direction_ = Direction::Left;
        move({ -speed_ * time_per_frame.asSeconds(), 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        direction_ = Direction::Right;
        move({ speed_ * time_per_frame.asSeconds(), 0.f });
    }
}
