#pragma once
#include <cstdint>

enum class Direction : std::uint8_t
{
    None,
    Up,
    Down,
    Left,
    Right
};

enum class GameState : std::uint8_t
{
    None,
    MainMenu,
    Settings,
    SaveLoad,
    Game,
    Battle,
    GameOver,
    Exit
};

enum class BattleState : std::uint8_t
{
    None,
    PlayerTurn,
    EnemyTurn,
    Victory,
    Defeat
};

enum class MenuState : std::uint8_t
{
    Main,
    Settings,
    SaveLoad
};

enum class MenuAction : std::uint8_t
{
    None,
    StartGame,
    OpenSettings,
    OpenSaveLoad,
    Exit
};
