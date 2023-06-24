/*
** EPITECH PROJECT, 2023
** snake header file
** File description:
** Nibbler
*/

#pragma once
#include "../IGameLib.hpp"
#include "../../Graphics/IGraphicLib.hpp"

namespace Arcade {

    class NIBBLER : public IGameLib {
        public:
            NIBBLER();
            ~NIBBLER();

            int snake_x = 1;
            int snake_y = 1;
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
                Food,
                F = Food,
                Snake,
                S = Snake
            };
            std::array<Grid, 19*19> _grid ={
            W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W,
            W, E, E, F, E, E, E, F, E, E, E, F, E, E, E, F, E, E, W,
            W, E, W, W, W, E, W, E, W, W, W, E, W, E, W, W, W, E, W,
            W, F, W, E, W, F, W, E, E, E, E, E, W, F, W, E, W, F, W,
            W, E, W, W, W, E, W, E, W, E, W, E, W, E, W, W, W, E, W,
            W, E, E, E, E, E, W, F, W, E, W, F, W, E, E, E, E, E, W,
            W, E, W, W, W, W, W, E, W, E, W, E, W, W, W, W, W, E, W,
            W, F, W, E, F, E, E, E, E, E, E, E, E, E, F, E, W, F, W,
            W, E, W, E, W, W, W, W, W, F, W, W, W, W, W, E, W, E, W,
            W, E, E, E, F, E, E, E, E, E, E, E, E, E, F, E, E, E, W,
            W, E, W, W, W, W, W, E, W, W, W, E, W, W, W, W, W, E, W,
            W, E, E, F, E, E, E, E, W, E, W, E, E, E, E, F, E, E, W,
            W, E, W, W, W, E, W, E, W, W, W, E, W, E, W, W, W, E, W,
            W, E, W, E, W, E, W, E, E, F, E, E, W, E, W, E, W, E, W,
            W, F, W, W, W, F, W, F, W, W, W, F, W, F, W, W, W, F, W,
            W, E, E, E, E, E, W, E, W, E, W, E, W, E, E, E, E, E, W,
            W, F, W, W, W, W, W, E, W, W, W, E, W, W, W, W, W, F, W,
            W, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, W,
            W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W
            };
    };
}
