/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** Arcade
*/

#pragma once
#include "Loader/Loader.hpp"
#include "../Graphics/IGraphicLib.hpp"
#include "../Games/IGameLib.hpp"
#include "../include/Assets.hpp"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>

namespace Arcade {
    class Arc {
        public:
            Arc() = default;
            ~Arc();
            void run(const std::string &lib_path, const std::string &game_path);
            void load_graphical(const std::string &path);
            void load_games(const std::string &path);
            const std::string menu_path = "lib/arcade_menu.so";
            std::vector<std::string> _gamesList = {"lib/arcade_snake.so", "lib/arcade_nibbler.so"};
            std::vector<std::string> _graphicalsList = {"lib/arcade_ncurses.so", "lib/arcade_sdl2.so", "lib/arcade_sfml.so"};
            void init();

            bool _run;

            std::unique_ptr<IGraphicLib> _graphical = nullptr;
            std::unique_ptr<IGameLib> _game = nullptr;
            std::unique_ptr<DLLoader<IGraphicLib>> _graphicalLibrary = nullptr;
            std::unique_ptr<DLLoader<IGameLib>> _gameLibrary = nullptr;
        private:
    };
}
