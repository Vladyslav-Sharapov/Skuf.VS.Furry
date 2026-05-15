#include "Core/Game.h"
#include <iostream>
#include <optional>

/// <summary>
/// Constructor for the Game class. Initializes the main window with the specified width, height, and title from the config namespace.
/// </summary>
Game::Game() :
	window_{
		sf::VideoMode{
			sf::Vector2u{ config::kWindowWidth, config::kWindowHeight },
			32U
		},
		config::kWindowTitle
}
{
	load_assets();

	main_menu_.setup(
		assets_.get_font("main_font"),
		assets_.get_texture("main_menu_bg"));

	tile_map_.set_position({ 128.f, 0.f });
	tile_map_.load(assets_.get_texture("tile_set"));

	player_.emplace(assets_.get_texture("char_01"));

}


/// <summary>
/// Main game loop. Runs until the window is closed. Updates and renders the game at a fixed frame rate defined in config::kFrameRate.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time time_since_last_update = sf::Time::Zero;

	constexpr sf::Time time_per_frame = sf::seconds(1.0f / static_cast<float>(config::kFrameRate));
	while (window_.isOpen())
	{
		process_events(); // as many as possible
		time_since_last_update += clock.restart();
		while (time_since_last_update > time_per_frame)
		{
			time_since_last_update -= time_per_frame;
			process_events(); // at least 60 fps
			update(time_per_frame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// Processes all pending events in the window's event queue. If the user closes the window or presses the Escape key, sets exit_game_ to true to signal the game loop to exit.
/// </summary>
void Game::process_events()
{
	while (const std::optional event = window_.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			exit_game_ = true;
		}

		if (game_state_ == GameState::MainMenu)
		{
			main_menu_.handle_event(*event);
		}
		else if (event->is<sf::Event::KeyPressed>())
		{
			process_keys_pressed(*event);
		}
		else if (event->is<sf::Event::KeyReleased>())
		{
			process_keys_released(*event);
		}
	}
}

/// <summary>
/// Processes a key press event. If the Escape key is pressed, sets exit_game_ to true to signal the game loop to exit.
/// </summary>
/// <param name="event">The key press event to process.</param>
void Game::process_keys_pressed(const sf::Event& event)
{
	if (const auto* key_pressed = event.getIf<sf::Event::KeyPressed>())
	{
		if (sf::Keyboard::Key::Escape == key_pressed->code)
		{
			exit_game_ = true;
		}
	}
}

void Game::process_keys_released(const sf::Event& event)
{
	if (const auto* key_released = event.getIf<sf::Event::KeyReleased>())
	{
		// Handle key releases if necessary
	}
}

/// <summary>
/// Pressing keys normally, not as text input
/// </summary>
void Game::check_keyboard_state()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		exit_game_ = true;
	}
}

/// <summary>
/// Updates the game state. This function is called at a fixed frame rate defined in config::kFrameRate. 
/// It checks the current state of the keyboard to see if any keys are being held down, and updates the game state accordingly. 
/// </summary>
/// <param name="delta_time"></param>
void Game::update(sf::Time delta_time)
{
	if (exit_game_)
	{
		window_.close();
		return;
	}

	switch (game_state_)
	{
	case GameState::MainMenu:
		handle_menu_action();
		break;

	case GameState::Game:
		if (!player_)
		{
			std::cerr << "Player does not exist in Game state.\n";
		}

		player_->update(delta_time);
		break;

	case GameState::Battle:
		// Update battle system later
		break;

	default:
		break;
	}
}

/// <summary>
/// Renders the current game state to the window. This function is called as often as possible, and should contain all the drawing code for the game.
/// </summary>
void Game::render()
{
	window_.clear(sf::Color::Black);

	switch (game_state_)
	{
	case GameState::MainMenu:
		main_menu_.render(window_);
		break;
	case GameState::Game:
		tile_map_.render(window_);
		player_->render(window_);
		break;
	}

	window_.display();
}

void Game::handle_menu_action()
{
	switch (main_menu_.selected_action())
	{
	case MenuAction::StartGame:
		game_state_ = GameState::Game;
		break;

	case MenuAction::OpenSettings:
		game_state_ = GameState::Settings;
		break;

	case MenuAction::OpenSaveLoad:
		game_state_ = GameState::SaveLoad;
		break;

	case MenuAction::Exit:
		exit_game_ = true;
		break;

	case MenuAction::None:
		break;
	}

	main_menu_.reset_action();
}

void Game::load_assets()
{
	// Load Textures
	if (!assets_.load_texture("main_menu_bg", "assets/tempDelete/MenuParalax.png"))
	{
		std::cerr << "Failed to load main menu background.\n";
	}

	if (!assets_.load_texture("tile_set", "assets/tempDelete/TileA1.png"))
	{
		std::cerr << "Failed to load tile set texture.\n";
	}

	if (!assets_.load_texture("char_01", "assets/tempDelete/01.png"))
	{
		std::cerr << "Failed to load player idle texture.\n";
	}

	// Load Fonts
	if (!assets_.load_font("main_font", "assets/Fonts/VL-Gothic-Regular.ttf"))
	{
		std::cerr << "Failed to load main font.\n";
	}
}
