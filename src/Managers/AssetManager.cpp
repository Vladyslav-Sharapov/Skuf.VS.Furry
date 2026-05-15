#include "Managers/AssetManager.h"

/// <summary>
/// Load texture from file and store it using string ID
/// </summary>
bool AssetManager::load_texture(const std::string& id, const std::string& file_path)
{
    sf::Texture texture;

    // Try to load texture from file
    if (!texture.loadFromFile(file_path))
    {
        return false;
    }

    // Store texture inside texture map
    textures_.emplace(id, std::move(texture));

    return true;
}

/// <summary>
/// Load font from file and store it using string ID
/// </summary>
bool AssetManager::load_font(const std::string& id, const std::string& file_path)
{
    sf::Font font;

    // Try to load font from file
    if (!font.openFromFile(file_path))
    {
        return false;
    }

    // Store font inside font map
    fonts_.emplace(id, std::move(font));

    return true;
}

/// <summary>
/// Return texture using string ID
/// </summary>
const sf::Texture& AssetManager::get_texture(const std::string& id) const
{
    return textures_.at(id);
}

/// <summary>
/// Return font using string ID
/// </summary>
const sf::Font& AssetManager::get_font(const std::string& id) const
{
    return fonts_.at(id);
}