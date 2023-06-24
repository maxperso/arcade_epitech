/*
** EPITECH PROJECT, 2023
** snake header file
** File description:
** Snake
*/

#pragma once
#include "../IGameLib.hpp"

namespace Arcade {

    class SNAKE : public IGameLib {
        public:
            SNAKE();
            ~SNAKE();

            int snake_x = 4;
            int snake_y = 5;
            int snake_body_x;
            int snake_body_y;
            int food_counter = 0;
            bool north;
            bool south;
            bool east = true;
            bool west;
            std::string getName() const override;
            void map_creator(Arcade::IGraphicLib &lib) override;
            void directions_assigner(Arcade::Keys key) override;
            void collisions() override;
            void drawSnake(Arcade::IGraphicLib &lib, int snake_body_x, int snake_body_y) override;
            void end_game_score(Arcade::IGraphicLib &lib) override;
            void change_libs(Arcade::IGraphicLib &lib, Arcade::Keys key) override;
            bool init(Arcade::IGraphicLib &lib) override;

        protected:
        private:
            enum Grid {
                    Empty,
                    E = Empty,
                    Wall,
                    W = Wall,
                    Snake,
                    S = Snake,
                    Food,
                    F = Food
                };
            std::array<Grid, 19*19> _grid ={
            W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, F, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W
            };
    };
}
