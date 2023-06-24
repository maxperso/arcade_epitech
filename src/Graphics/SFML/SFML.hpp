/*
** EPITECH PROJECT, 2023
** sfml header file
** File description:
** sfml
*/

#pragma once

#include "../IGraphicLib.hpp"
#include <SFML/Graphics.hpp>

//to compile use these flags: -lsfml-graphics -lsfml-window -lsfml-system

namespace Arcade {

    class SFML : public IGraphicLib {
    public:
        SFML();
        ~SFML() override;
        
        sf::RenderWindow window;
        sf::VideoMode videoMode;
        int lib_count;
        std::string getName() const override;
        void popWindow(std::string const& title, int width, int height) override;
        Keys getLastEvent() override;
        void mapManager(Assets &a, int x, int y) override;
        void drawText(std::string text, int x, int y) override;
        void closeWindow() override;
        int select(Arcade::Keys key) override;
        void refresh() override;

    private:
    };
}
