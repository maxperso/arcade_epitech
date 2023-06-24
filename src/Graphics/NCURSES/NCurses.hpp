/*
** EPITECH PROJECT, 2023
** ncurses header file
** File description:
** ncurses
*/

#pragma once

#include "../IGraphicLib.hpp"
#include <ncurses.h>

//to compile, use these flags: -lncurses

namespace Arcade {

    class NCURSES : public IGraphicLib {
    public:
        NCURSES();
        ~NCURSES() override;

        static WINDOW* win;
        int lib_count;
        std::string win_title;
        std::string getName() const override;
        void popWindow(std::string const& title, int width, int height) override;
        Keys getLastEvent() override;
        void mapManager(Assets &a, int x, int y) override;
        void drawText(std::string text, int x, int y) override;
        void closeWindow() override;
        int select(Arcade::Keys key) override;
        void printFile(Assets &a, fs::path file_path, int x, int y);
        void refresh() override;

    };
}
