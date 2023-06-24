/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** Snake
*/

#include "Snake.hpp"
#include "../../Core/Arcade.cpp"
#include "../../Core/Arcade.hpp"

// declare a global random number generator
std::default_random_engine rng;
namespace Arcade {

    Assets wall {
        .image_path = "assets/image/cobble_sprite.png",
        .character = "assets/text/brick.txt",
        .color = "blue",
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

    Assets apple {
        .image_path = "assets/image/food_snake_sprite.png",
        .character = "assets/text/food.txt",
        .color = "green",
        .width = 32,
        .height = 32
    };

    Assets snake_head_north {
        .image_path = "assets/image/snake_head_north.png",
        .character = "assets/text/snake_head_north.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    Assets snake_head_south {
        .image_path = "assets/image/snake_head_south.png",
        .character = "assets/text/snake_head_south.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    Assets snake_head_east {
        .image_path = "assets/image/snake_head_east.png",
        .character = "assets/text/snake_head_east.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    Assets snake_head_west {
        .image_path = "assets/image/snake_head_west.png",
        .character = "assets/text/snake_head_west.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    Assets snake_body_horizontal {
        .image_path = "assets/image/snake_body_x.png",
        .character = "assets/text/snake_body_x.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    Assets snake_body_vertical {
        .image_path = "assets/image/snake_body_y.png",
        .character = "assets/text/snake_body_y.txt",
        .color = "red_green",
        .width = 32,
        .height = 32
    };

    extern "C" Arcade::IGameLib *getInstance()
    {
        return new SNAKE();
    }

    SNAKE::SNAKE()
    {
       
    }
    SNAKE::~SNAKE()
    {
       
    }

    void SNAKE::map_creator(Arcade::IGraphicLib &lib)
    {
        for (int i = 0; i <= 18; i++) {
            for (int j = 0; j <= 18; j++) {
                if (_grid[i * 19 + j] == Grid::Wall)
                    lib.mapManager(wall, i, j);
                if (_grid[i * 19 + j] == Grid::Empty)
                    lib.mapManager(grass, i, j);
                if (_grid[i * 19 + j] == Grid::Food)
                    lib.mapManager(apple, i, j);
            }
        }
    }

    int chooseNumber(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    void SNAKE::directions_assigner(Arcade::Keys key)
    {
        if (key == Keys::LEFT) {
            west = true;
            north = false;
            south = false;
            east = false;
        }
        if (key == Keys::RIGHT) {
            east = true;
            north = false;
            south = false;
            west = false;
        }
        if (key == Keys::UP) {
            north = true;
            east = false;
            south = false;
            west = false;
        }
        if (key == Keys::DOWN) {
            south = true;
            east = false;
            north = false;
            west = false;
        }
    }

    void SNAKE::collisions()
    {
        if (east == true)
            snake_y++;
        if (west == true)
            snake_y--;
        if (north == true)
            snake_x--;
        if (south == true)
            snake_x++;
    }

    void SNAKE::drawSnake(Arcade::IGraphicLib &lib, int snake_body_x, int snake_body_y)
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
            lib.mapManager(snake_body_horizontal, snake_body_x, snake_body_y);
        if (west == true && snake_body_x == snake_x && snake_body_y == snake_y + 1)
            lib.mapManager(snake_body_horizontal, snake_body_x, snake_body_y);
        if (north == true && snake_body_x == snake_x + 1 && snake_body_y == snake_y)
            lib.mapManager(snake_body_vertical, snake_body_x, snake_body_y);
        if (south == true && snake_body_x == snake_x - 1 && snake_body_y == snake_y)
            lib.mapManager(snake_body_vertical, snake_body_x, snake_body_y);
    }

    void SNAKE::end_game_score(Arcade::IGraphicLib &lib)
    {
        Arcade::Arc my_arc;

        lib.closeWindow();
        lib.popWindow("Score Snake " + lib.getName(), 130, 70);
        std::ifstream file("scores/highscore_snake.txt");
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
                    my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[0]);
                if (lib.getName() == "SDL")
                    my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[0]);
                if (lib.getName() == "SFML")
                    my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[0]);
            }
            if (key == Arcade::Keys::Q) {
                lib.closeWindow();
                exit(0);
            }
            lib.refresh();
        }
    }

    void SNAKE::change_libs(Arcade::IGraphicLib &lib, Arcade::Keys key)
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
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[0]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[0]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[0]);
        }
        if (key == Arcade::Keys::L) { // next lib
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[0]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[0]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[0]);
        }
        if (key == Arcade::Keys::G) { // next game
            lib.closeWindow();
            if (lib.getName() == "NCURSES")
                my_arc.run(my_arc._graphicalsList[1], my_arc._gamesList[1]);
            if (lib.getName() == "SDL")
                my_arc.run(my_arc._graphicalsList[2], my_arc._gamesList[1]);
            if (lib.getName() == "SFML")
                my_arc.run(my_arc._graphicalsList[0], my_arc._gamesList[1]);
        }
    }

    bool SNAKE::init(Arcade::IGraphicLib &lib)
    {
        Arcade::Arc my_arc;

        rng.seed(853569);
        lib.popWindow("Snake " + lib.getName(), 130, 70);
        const int interval_seconds = 0.5;
        auto start_time = std::chrono::steady_clock::now();
        while(1) {
            std::ifstream file("scores/highscore_snake.txt");
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
                    _grid[chooseNumber(1, 17) * 19 + chooseNumber(1, 17)] = Grid::Food;
                    food_counter++;
                }
                if (_grid[snake_x * 19 + snake_y] == Grid::Wall)
                    end_game_score(lib);
                start_time = current_time;
            }
            lib.drawText("Score: " + std::to_string(food_counter), 0, 0);
            lib.drawText("Highscore: " + std::to_string(highscore), 8, 0);
            change_libs(lib, key);
            if (food_counter > highscore) {
                    std::ofstream file("scores/highscore_snake.txt");
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

    std::string SNAKE::getName() const
    {
        return "Snake";
    }

}