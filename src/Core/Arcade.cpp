/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** Arcade
*/

#include "Arcade.hpp"

void Arcade::Arc::run(const std::string &lib_path, const std::string &game_path)
{
    load_graphical(lib_path);
    load_games(game_path);

    auto clock = std::chrono::steady_clock::now();

    _run = true;
    while (_run == true) {
        if (_run == false)
            break;
        auto now = std::chrono::steady_clock::now();
        auto elapsed = now - clock;
        clock = now;
    
        init();
    }
}

void Arcade::Arc::init()
{
    _game->init(*_graphical);
}

void Arcade::Arc::load_graphical(const std::string &path)
{
    std::string copy_path = path;
    try {
        _graphicalLibrary = std::make_unique<DLLoader<IGraphicLib>>(copy_path);
        _graphical = std::unique_ptr<Arcade::IGraphicLib>(_graphicalLibrary->getInstance());
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Arcade::Arc::load_games(const std::string &path)
{
    std::string copy_path = path;
    try {
        _gameLibrary = std::make_unique<DLLoader<IGameLib>>(copy_path);
        _game.reset(_gameLibrary->getInstance());
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

Arcade::Arc::~Arc()
{
    _game = nullptr;
    _graphical = nullptr;
}
