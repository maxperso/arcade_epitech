/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "../IGameLib.hpp"
#include "../../Core/Arcade.hpp"
#include "../../include/Assets.hpp"
#include "../../Graphics/IGraphicLib.hpp"
#include "../../Core/Arcade.cpp"
#include "../../Core/Arcade.hpp"

Assets wall {
    .image_path = "assets/image/brick_sprite.png",
    .character = "assets/text/brick.txt",
    .color = "red",
    .width = 32,
    .height = 32
};

Assets grass {
    .image_path = "assets/image/grass_sprite.png",
    .character = "assets/text/grass.txt",
    .color = "green",
    .width = 32,
    .height = 32
};

Assets shrooms {
    .image_path = "assets/image/food_nibbler_sprite.png",
    .character = "assets/text/food.txt",
    .color = "green",
    .width = 32,
    .height = 32
};

Assets snake_head_north {
    .image_path = "assets/image/nibbler_head_north.png",
    .character = "assets/text/snake_head_north.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_head_south {
    .image_path = "assets/image/nibbler_head_south.png",
    .character = "assets/text/snake_head_south.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_head_east {
    .image_path = "assets/image/nibbler_head_east.png",
    .character = "assets/text/snake_head_east.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_head_west {
    .image_path = "assets/image/nibbler_head_west.png",
    .character = "assets/text/snake_head_west.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_body_west {
    .image_path = "assets/image/nibbler_body_west.png",
    .character = "assets/text/snake_body_x.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_body_north {
    .image_path = "assets/image/nibbler_body_north.png",
    .character = "assets/text/snake_body_y.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_body_south {
    .image_path = "assets/image/nibbler_body_south.png",
    .character = "assets/text/snake_body_y.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

Assets snake_body_east {
    .image_path = "assets/image/nibbler_body_east.png",
    .character = "assets/text/snake_body_x.txt",
    .color = "red_green",
    .width = 32,
    .height = 32
};

namespace Arcade {

    extern "C" Arcade::IGameLib *getInstance()
    {
        return new NIBBLER();
    }


    NIBBLER::NIBBLER()
    {
       
    }

    NIBBLER::~NIBBLER()
    {
       
    }

    void NIBBLER::map_creator(Arcade::IGraphicLib &lib)
    {
        for (int i = 0; i <= 18; i++) {
            for (int j = 0; j <= 18; j++) {
                if (_grid[i * 19 + j] == Grid::Wall)
                    lib.mapManager(wall, i, j);
                if (_grid[i * 19 + j] == Grid::Empty)
                    lib.mapManager(grass, i, j);
                if (_grid[i * 19 + j] == Grid::Food)
                    lib.mapManager(shrooms, i, j);
            }
        }
    }

    void NIBBLER::directions_assigner(Arcade::Keys key)
    {
        if (key == Arcade::Keys::LEFT) {
            west = true;
            north = false;
            south = false;
            east = false;
        }
        if (key == Arcade::Keys::RIGHT) {
            east = true;
            north = false;
            south = false;
            west = false;
        }
        if (key == Arcade::Keys::UP) {
            north = true;
            west = false;
            south = false;
            east = false;
        }
        if (key == Arcade::Keys::DOWN) {
            south = true;
            west = false;
            north = false;
            east = false;
        }
    }

    void NIBBLER::collisions()
    {
        if (west == true && _grid[snake_x * 19 + snake_y - 1] != Grid::Wall)
            snake_y--;
        if (east == true && _grid[snake_x * 19 + snake_y + 1] != Grid::Wall)
            snake_y++;
        if (north == true && _grid[(snake_x - 1) * 19 + snake_y] != Grid::Wall)
            snake_x--;
        if (south == true && _grid[(snake_x + 1) * 19 + snake_y] != Grid::Wall)
            snake_x++;
    }

    void NIBBLER::drawSnake(Arcade::IGraphicLib &lib, int snake_body_x, int snake_body_y)
    {
        if (east == true)
            lib.mapManager(snake_head_east, snake_x, snake_y);
        if (west == true)
            lib.mapManager(snake_head_west, snake_x, snake_y);
        if (north == true)
            lib.mapManager(snake_head_north, snake_x, snake_y);
        if (south == true)
            lib.mapManager(snake_head_south, snake_x, snake_y);
        if (east == true && snake_body_x == snake_x && snake_body_y == snake_y - 1)
            lib.mapManager(snake_body_east, snake_body_x, snake_body_y);
        if (west == true && snake_body_x == snake_x && snake_body_y == snake_y + 1)
            lib.mapManager(snake_body_west, snake_body_x, snake_body_y);
        if (north == true && snake_body_x == snake_x + 1 && snake_body_y == snake_y)
            lib.mapManager(snake_body_north, snake_body_x, snake_body_y);
        if (south == true && snake_body_x == snake_x - 1 && snake_body_y == snake_y)
            lib.mapManager(snake_body_south, snake_body_x, snake_body_y);
    }

    void NIBBLER::end_game_score(Arcade::IGraphicLib &lib)
    {
        Arcade::Arc my_arc;

        lib.popWindow("Score Nibbler " + lib.getName(), 130, 70);
        std::ifstream file("scores/highscore_nibbler.txt");
        std::string line;
        std::getline(file, line);
        int highscore = std::stoi(line);
        while (1) {
            Arcade::Keys key = lib.getLastEvent();
            lib.drawText("Your Score was: " + std::to_string(food_counter), 1, 1);
            lib.drawText("Your Highscore is: " + std::to_string(highscore), 1, 3);
            lib.drawText("Press ESC to return to the menu", 1, 5);
            lib.drawText("Press ENTER to restart the game", 1, 7);
            lib.drawText("Press Q to quit the game", 1, 9);
            if (key == Arcade::Keys::ESC) {
                lib.closeWindow();
                if (lib.getName() == "NCURSES")
                    my_arc.run(my_arc._graphicalsList[0], my_arc.menu_path);
                if (lib.getName() == "SDL")
                    my_arc.run(my_arc._graphicalsList[1], my_arc.menu_path);
                if (lib.getName() == "SFML")
                    my_arc.run(my_arc._graphicalsList[2], my_arc.menu_path);
            }
            if (key == Arcade::Keys::ENTER) {
                lib.closeWindow();
                if (lib.getName() == "NCURSES")
                    my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[1]);
                if (lib.getName() == "SDL")
                    my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[1]);
                if (lib.getName() == "SFML")
                    my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[1]);
            }
            if (key == Arcade::Keys::Q) {
                lib.closeWindow();
                exit(0);
            }
            lib.refresh();
        }
    }

    void NIBBLER::change_libs(Arcade::IGraphicLib &lib, Arcade::Keys key)
    {
        Arcade::Arc my_arc;

        if (key == Arcade::Keys::M) { // menu
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[0], my_arc.menu_path);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[1], my_arc.menu_path);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[2], my_arc.menu_path);
        }
        if (key == Arcade::Keys::R) { // restart
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[1]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[1]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[1]);
        }
        if (key == Arcade::Keys::L) { // next lib
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[1]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[1]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[1]);
        }
        if (key == Arcade::Keys::G) { // next game
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[0]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[0]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[0]);
        }
    }

    bool NIBBLER::init(Arcade::IGraphicLib &lib)
    {
        Arcade::Arc my_arc;

        lib.popWindow("Nibbler " + lib.getName(), 130, 70);
        const int interval_seconds = 0.5; // Interval time in seconds
        auto start_time = std::chrono::steady_clock::now(); // Get current time
        while (1) {
            std::ifstream file("scores/highscore_nibbler.txt");
            std::string line;
            std::getline(file, line);
            int highscore = std::stoi(line);
            auto current_time = std::chrono::steady_clock::now();
            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time);
            map_creator(lib);
            Arcade::Keys key = lib.getLastEvent();
            if (elapsed_time.count() >= interval_seconds) {
                directions_assigner(key);
                snake_body_x = snake_x;
                snake_body_y = snake_y;
                collisions();
                if (_grid[snake_x * 19 + snake_y] == Grid::Food) {
                    _grid[snake_x * 19 + snake_y] = Grid::Empty;
                    food_counter++;
                }
                if (food_counter == 4)
                    end_game_score(lib);
                start_time = current_time;
            }
            lib.drawText("Score: " + std::to_string(food_counter), 0, 0);
            lib.drawText("Highscore: " + std::to_string(highscore), 8, 0);
            change_libs(lib, key);
            if (food_counter > highscore) {
                    std::ofstream file("scores/highscore_nibbler.txt");
                    file << food_counter;
            }
            if (key == Arcade::Keys::ESC) {
                lib.closeWindow();
                exit (0);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            drawSnake(lib, snake_body_x, snake_body_y);
            lib.refresh();
        }
        return true;
    }

    std::string NIBBLER::getName() const
    {
        return "Nibbler";
    }
}
