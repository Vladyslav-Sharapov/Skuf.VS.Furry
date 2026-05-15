#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdexcept>

#include "Core/Config.h"
#include "Entities/Player.h"
#include "Managers/AssetManager.h"
#include "UI/MainMenu.h"
#include "World/TileMap.h"

class Game
{
public:
	Game();
	~Game() = default;
	void run();

private:
	void process_events();
	void process_keys_pressed(const sf::Event& event);
	void process_keys_released(const sf::Event& event);

	void check_keyboard_state();

	void update(sf::Time delta_time);
	void render();

	void handle_menu_action();

	void load_assets();

	sf::RenderWindow window_; // main SFML window

	sf::Font font_;

	AssetManager assets_;

	sf::Font main_font_;
	MainMenu main_menu_;

	TileMap tile_map_;

	std::optional<Player> player_;

	GameState game_state_ = GameState::MainMenu;

	bool exit_game_{false}; // control exiting game
};
