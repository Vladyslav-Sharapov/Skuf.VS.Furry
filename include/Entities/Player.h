#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	explicit Player(const sf::Texture& texture);

	void update(sf::Time time_per_frame) override;
	void render(sf::RenderWindow& window) const override;

private:
	void setup_sprite();
	void key_handler(sf::Time time_per_frame);

	float speed_ = 100.f; // pixels per second
};