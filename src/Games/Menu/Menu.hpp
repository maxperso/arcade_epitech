/*
** EPITECH PROJECT, 2023
** menu header file
** File description:
** Menu
*/

#pragma once
#include "../IGameLib.hpp"
#include "../../Graphics/IGraphicLib.hpp"

namespace Arcade {

    class MENU : public IGameLib {
        public:
            MENU();
            ~MENU();

            int counter;
            std::string getName() const override;
            bool init(Arcade::IGraphicLib &lib) override;
            void directions_assigner(Arcade::Keys key) override;
            void collisions() override;
            void drawSnake(Arcade::IGraphicLib &lib, int snake_body_x, int snake_body_y) override;
            void end_game_score(Arcade::IGraphicLib &lib) override;
            void change_libs(Arcade::IGraphicLib &lib, Arcade::Keys key) override;
            void map_creator(Arcade::IGraphicLib &lib) override;

        protected:
        private:
    };
}
