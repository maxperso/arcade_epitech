/*
** EPITECH PROJECT, 2023
** Menu cpp file
** File description:
** Menu
*/

#include "Menu.hpp"
#include "../IGameLib.hpp"
#include "../../Core/Arcade.hpp"
#include "../../Core/Arcade.cpp"
#include "../../include/Assets.hpp"
#include "../../Graphics/IGraphicLib.hpp"

namespace Arcade {

    Assets map_menu{
        .image_path = "assets/image/arcade_menu_sprite.png",
        .character = "assets/text/menu.txt",
        .color = "red_black",
        .width = 992,
        .height = 192
    };

    Assets lib_title{
        .image_path = "assets/image/libraries_menu_sprite.png",
        .character = "assets/text/lib_title.txt",
        .color = "yellow_black",
        .width = 192,
        .height = 64
    };
    Assets game_title{
        .image_path = "assets/image/games_menu_sprite.png",
        .character = "assets/text/game_title.txt",
        .color = "yellow_black",
        .width = 192,
        .height = 64
    };

    Assets game_snake{
        .image_path = "assets/image/snake_menu_sprite.png",
        .character = "assets/text/game_snake.txt",
        .color = "red_black",
        .width = 128,
        .height = 32
    };

    Assets game_nibbler{
        .image_path = "assets/image/nibbler_menu_sprite.png",
        .character = "assets/text/game_nibbler.txt",
        .color = "red_black",
        .width = 128,
        .height = 32
    };

    Assets lib_sdl{
        .image_path = "assets/image/sdl_menu_sprite.png",
        .character = "assets/text/lib_sdl.txt",
        .color = "red_black",
        .width = 128,
        .height = 32
    };

    Assets lib_ncurses{
        .image_path = "assets/image/ncurses_menu_sprite.png",
        .character = "assets/text/lib_ncurses.txt",
        .color = "red_black",
        .width = 128,
        .height = 32
    };

    Assets lib_sfml{
        .image_path = "assets/image/sfml_menu_sprite.png",
        .character = "assets/text/lib_sfml.txt",
        .color = "red_black",
        .width = 128,
        .height = 32
    };

    Assets lib_sdl_selected{
        .image_path = "assets/image/sdl_selected.png",
        .character = "assets/text/lib_sdl.txt",
        .color = "red",
        .width = 128,
        .height = 32
    };

    Assets lib_ncurses_selected{
        .image_path = "assets/image/ncurses_selected.png",
        .character = "assets/text/lib_ncurses.txt",
        .color = "red",
        .width = 128,
        .height = 32
    };

    Assets lib_sfml_selected{
        .image_path = "assets/image/sfml_selected.png",
        .character = "assets/text/lib_sfml.txt",
        .color = "red",
        .width = 128,
        .height = 32
    };

    Assets game_snake_selected{
        .image_path = "assets/image/snake_selected.png",
        .character = "assets/text/game_snake.txt",
        .color = "red",
        .width = 128,
        .height = 32
    };

    Assets game_nibbler_selected{
        .image_path = "assets/image/nibbler_selected.png",
        .character = "assets/text/game_nibbler.txt",
        .color = "red",
        .width = 128,
        .height = 32
    };

    MENU::MENU()
    {

    }

    MENU::~MENU()
    {

    }

    extern "C" Arcade::IGameLib *getInstance()
    {
        return new MENU();
    }

    void MENU::change_libs(IGraphicLib &lib, Arcade::Keys key)
    {
        Arcade::Arc my_arc;

        if (key == Arcade::Keys::ENTER && counter >= 0 && counter <= 2) {
            lib.closeWindow();
            if (counter == 0)
                my_arc.run(my_arc._graphicalsList[0], my_arc.menu_path);
            if (counter == 1)
                my_arc.run(my_arc._graphicalsList[1], my_arc.menu_path);
            if (counter == 2)
                my_arc.run(my_arc._graphicalsList[2], my_arc.menu_path);
        }
        if (key == Arcade::Keys::ENTER && counter >= 3 && counter <= 4) {
            lib.closeWindow();
            if (counter == 3 && lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[0]);
            if (counter == 3 && lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[0]);
            if (counter == 3 && lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[0]);
            if (counter == 4 && lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[1]);
            if (counter == 4 && lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[1]);
            if (counter == 4 && lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[1]);
        }
    }

    bool MENU::init(IGraphicLib &lib)
    {
        Arcade::Arc my_arc;

        lib.popWindow("Menu " + lib.getName(), 120, 40);
        while (1) {
            lib.mapManager(map_menu, 2, 3);
            lib.mapManager(lib_title, 11, 8);
            lib.mapManager(game_title, 11, 23);
            lib.mapManager(lib_ncurses, 14, 9);
            lib.mapManager(lib_sdl, 15, 9);
            lib.mapManager(lib_sfml, 16, 9);
            lib.mapManager(game_snake, 14, 24);
            lib.mapManager(game_nibbler, 15, 24);
            Arcade::Keys key = lib.getLastEvent();
            counter = lib.select(key);
            if (counter == 0)
                lib.mapManager(lib_ncurses_selected, 14, 9);
            if (counter == 1)
                lib.mapManager(lib_sdl_selected, 15, 9);
            if (counter == 2)
                lib.mapManager(lib_sfml_selected, 16, 9);
            if (counter == 3)
                lib.mapManager(game_snake_selected, 14, 24);
            if (counter == 4)
                lib.mapManager(game_nibbler_selected, 15, 24);
            if (key == Arcade::Keys::ESC) {
                lib.closeWindow();
                exit (0);
            }
            change_libs(lib, key);
            lib.refresh();
        }
        return true;
    }

    std::string MENU::getName() const
    {
        return "Menu";
    }

    //These functions serve no purpose, but are required by the interface (SORRY NEIL)
    void MENU::directions_assigner(Arcade::Keys key)
    {
        if (key == Arcade::Keys::NONE)
            return;
    }

    void MENU::map_creator(IGraphicLib &lib)
    {
        lib.getName();
    }

    void MENU::collisions()
    {

    }

    void MENU::drawSnake(IGraphicLib &lib, int snake_x, int snake_y)
    {
        lib.getName();
        snake_x = snake_y;
        snake_y = snake_x;
    }

    void MENU::end_game_score(IGraphicLib &lib)
    {
        lib.getName();
    }
}
