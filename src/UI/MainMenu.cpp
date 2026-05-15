#include "UI/MainMenu.h"

MainMenu::MainMenu() = default; // Default constructor, no special initialization needed

/// <summary>
/// Set up the main menu with the provided font and background texture. 
/// This function initializes the background sprite, creates the menu options as text objects, and positions them on the screen. 
/// It also sets up the buttons for each menu option and updates their colors based on the currently selected option.
/// </summary>
/// <param name="font">The font to use for the menu options.</param>
/// <param name="background_texture">The texture to use for the background.</param>
void MainMenu::setup(
    const sf::Font& font,
    const sf::Texture& background_texture)
{
    // Create background sprite
    background_.emplace(background_texture);

    // Create menu options
    options_ = {
        sf::Text{ font, "Start Game", 40 },
        sf::Text{ font, "Settings", 40 },
        sf::Text{ font, "Save / Load", 40 },
        sf::Text{ font, "Exit", 40 }
    };

    buttons_.clear();

    constexpr sf::Vector2f button_size{ 360.f, 55.f };
    constexpr sf::Vector2f button_start_position{ 485.f, 390.f };
    constexpr float button_spacing = 65.f;

    // Create buttons and position text
    for (std::size_t i = 0; i < options_.size(); ++i)
    {
        sf::RectangleShape button{ button_size };

        button.setPosition({
            button_start_position.x,
            button_start_position.y + static_cast<float>(i) * button_spacing
            });

        button.setFillColor(sf::Color(20, 20, 20, 150));
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color(180, 180, 180, 180));

        buttons_.push_back(button);

        const sf::FloatRect text_bounds = options_[i].getLocalBounds();

        // Center text origin
        options_[i].setOrigin({
            text_bounds.position.x + text_bounds.size.x / 2.f,
            text_bounds.position.y + text_bounds.size.y / 2.f
            });

        // Position text in button center
        options_[i].setPosition({
            button.getPosition().x + button_size.x / 2.f,
            button.getPosition().y + button_size.y / 2.f
            });
    }

    update_option_colours();
}

/// <summary>
/// Handle keyboard input for the menu
/// </summary>
void MainMenu::handle_event(const sf::Event& event)
{
    // Check if user pressed a key
    if (const auto* key_pressed = event.getIf<sf::Event::KeyPressed>())
    {
        // Move selection up
        if (key_pressed->code == sf::Keyboard::Key::Up ||
            key_pressed->code == sf::Keyboard::Key::W)
        {
            move_up();
        }
        // Move selection down
        else if (key_pressed->code == sf::Keyboard::Key::Down ||
            key_pressed->code == sf::Keyboard::Key::S)
        {
            move_down();
        }
        // Confirm selected option
        else if (key_pressed->code == sf::Keyboard::Key::Enter)
        {
            confirm_selection();
        }
    }
}

/// <summary>
/// Render the main menu to the window. T
/// his function draws the background, buttons, and menu options to the provided render window.
/// </summary>
/// <param name="window">The render window to draw the menu on.</param>
void MainMenu::render(sf::RenderWindow& window) const
{
    if (background_)
    {
        window.draw(*background_);
    }

    for (const sf::RectangleShape& button : buttons_)
    {
        window.draw(button);
    }

    for (const sf::Text& option : options_)
    {
        window.draw(option);
    }
}

/// <summary>
/// Return selected menu action
/// </summary>
MenuAction MainMenu::selected_action() const
{
    return selected_action_;
}

/// <summary>
/// Reset selected action after game handles it
/// </summary>
void MainMenu::reset_action()
{
    selected_action_ = MenuAction::None;
}

/// <summary>
/// Move menu selection up
/// Wrap to bottom if at top
/// </summary>
void MainMenu::move_up()
{
    if (selected_index_ > 0)
    {
        --selected_index_;
    }
    else
    {
        selected_index_ = options_.size() - 1;
    }

    update_option_colours();
}

/// <summary>
/// Move menu selection down
/// Wrap to top if at bottom
/// </summary>
void MainMenu::move_down()
{
    if (selected_index_ < options_.size() - 1)
    {
        ++selected_index_;
    }
    else
    {
        selected_index_ = 0;
    }

    update_option_colours();
}

/// <summary>
/// Convert selected menu index into menu action
/// </summary>
void MainMenu::confirm_selection()
{
    switch (selected_index_)
    {
    case 0:
        selected_action_ = MenuAction::StartGame;
        break;

    case 1:
        selected_action_ = MenuAction::OpenSettings;
        break;

    case 2:
        selected_action_ = MenuAction::OpenSaveLoad;
        break;

    case 3:
        selected_action_ = MenuAction::Exit;
        break;

    default:
        selected_action_ = MenuAction::None;
        break;
    }
}

/// <summary>
/// Update selected button and text colours
/// </summary>
void MainMenu::update_option_colours()
{
    for (std::size_t i = 0; i < options_.size(); ++i)
    {
        if (i == selected_index_)
        {
            options_[i].setFillColor(sf::Color(0, 220, 255));

            buttons_[i].setFillColor(sf::Color(0, 220, 255, 45));

            buttons_[i].setOutlineColor(sf::Color(0, 220, 255));
        }
        else
        {
            options_[i].setFillColor(sf::Color::White);

            buttons_[i].setFillColor(sf::Color(20, 20, 20, 130));

            buttons_[i].setOutlineColor(sf::Color(180, 180, 180, 130));
        }
    }
}