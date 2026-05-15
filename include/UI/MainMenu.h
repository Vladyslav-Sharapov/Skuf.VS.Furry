#pragma once

#include "Core/GameTypes.h"

#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu
{
public:
    MainMenu();

    void setup(const sf::Font& font, const sf::Texture& background_texture);

    void handle_event(const sf::Event& event);
    void render(sf::RenderWindow& window) const;

    [[nodiscard]]
    MenuAction selected_action() const;

    void reset_action();

private:
    void move_up();
    void move_down();
    void confirm_selection();
    void update_option_colours();

    std::optional<sf::Sprite> background_;

    std::vector<sf::RectangleShape> buttons_;
    std::vector<sf::Text> options_;
    std::size_t selected_index_ = 0;

    MenuAction selected_action_ = MenuAction::None;
};