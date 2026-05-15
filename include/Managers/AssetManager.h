#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <unordered_map>

class AssetManager
{
public:
    bool load_texture(const std::string& id, const std::string& file_path);
    bool load_font(const std::string& id, const std::string& file_path);

    [[nodiscard]]
    const sf::Texture& get_texture(const std::string& id) const;

    [[nodiscard]]
    const sf::Font& get_font(const std::string& id) const;

private:
    // Store all loaded textures
    std::unordered_map<std::string, sf::Texture> textures_;

    // Store all loaded fonts
    std::unordered_map<std::string, sf::Font> fonts_;
};