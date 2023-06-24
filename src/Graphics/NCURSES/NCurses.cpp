/*
** EPITECH PROJECT, 2023
** ncurses lib C++ file
** File description:
** sfml
*/

#include "NCurses.hpp"
#include "../IGraphicLib.hpp"

namespace Arcade {

    WINDOW* NCURSES::win = nullptr;

    NCURSES::NCURSES()
    {
       
    }
    NCURSES::~NCURSES()
    {
       
    }

    extern "C" Arcade::IGraphicLib *getInstance()
    {
        return new NCURSES();
    }

    void NCURSES::popWindow(std::string const& title, int width, int height)
    {
        this->win_title = title;
        initscr();
        cbreak();
        nodelay(stdscr, TRUE);
        curs_set(0);
        start_color();
        noecho();
        keypad(stdscr, true);
        this->lib_count = 0;
        this->win = newwin(height, width, 0, 0);
    }

    Keys NCURSES::getLastEvent()
    {
        int ch = getch();
        if (ch == ERR) {
            return Arcade::Keys::NONE;
        } else {
            switch (ch) {
                case KEY_UP:
                    return Arcade::Keys::UP;
                case KEY_DOWN:
                    return Arcade::Keys::DOWN;
                case KEY_LEFT:
                    return Arcade::Keys::LEFT;
                case KEY_RIGHT:
                    return Arcade::Keys::RIGHT;
                case '\n':
                    return Arcade::Keys::ENTER;
                case ' ':
                    return Arcade::Keys::SPACE;
                case KEY_BACKSPACE:
                    return Arcade::Keys::BACKSPACE;
                case KEY_DC:
                    return Arcade::Keys::DELETE;
                case '\t':
                    return Arcade::Keys::TAB;
                case 27: // Escape key
                    return Arcade::Keys::ESC;
                default:
                    // Pour les lettres, return code ASCII
                    if (ch >= 'a' && ch <= 'z') {
                        return static_cast<Arcade::Keys>(ch - 'a' + Arcade::Keys::A);
                    } else if (ch >= 'A' && ch <= 'Z') {
                        return static_cast<Arcade::Keys>(ch - 'A' + Arcade::Keys::A);
                    } else {
                        return Arcade::Keys::NONE;
                    }
            }
        }
    }

    void NCURSES::drawText(std::string text, int x, int y)
    {
        x = x*2;
        wattron(this->win, COLOR_PAIR(3));
        mvwprintw(this->win, y, x, "%s", text.c_str());
        wattroff(this->win, COLOR_PAIR(3));
    }

    void NCURSES::mapManager(Assets &a, int y, int x)
    {
        x = x*2;
        y++;
        printFile(a, a.character.c_str(), x, y);
    }

    void NCURSES::printFile(Assets &a, fs::path file_path, int x, int y)
    {
        init_pair(1, COLOR_WHITE, COLOR_RED);
        init_pair(2, COLOR_WHITE, COLOR_GREEN);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_WHITE, COLOR_BLUE);
        init_pair(5, COLOR_RED, COLOR_BLACK);
        init_pair(6, COLOR_RED, COLOR_GREEN);

        std::ifstream file(file_path);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                if (a.color == "red")
                    wattron(this->win, COLOR_PAIR(1));
                else if (a.color == "green")
                    wattron(this->win, COLOR_PAIR(2));
                else if (a.color == "yellow_black")
                    wattron(this->win, COLOR_PAIR(3));
                else if (a.color == "blue")
                    wattron(this->win, COLOR_PAIR(4));
                else if (a.color == "red_black")
                    wattron(this->win, COLOR_PAIR(5));
                else if (a.color == "red_green")
                    wattron(this->win, COLOR_PAIR(6));
                mvwprintw(this->win, y, x, "%s", line.c_str());
                if (a.color == "red")
                    wattroff(this->win, COLOR_PAIR(1));
                else if (a.color == "green")
                    wattroff(this->win, COLOR_PAIR(2));
                else if (a.color == "yellow_black")
                    wattroff(this->win, COLOR_PAIR(3));
                else if (a.color == "blue")
                    wattroff(this->win, COLOR_PAIR(4));
                else if (a.color == "red_black")
                    wattroff(this->win, COLOR_PAIR(5));
                else if (a.color == "red_green")
                    wattroff(this->win, COLOR_PAIR(6));
                ++y;
            }
            file.close();
        }
    }

    int NCURSES::select(Arcade::Keys key)
    {
        if (key == Arcade::Keys::DOWN) {
            this->lib_count++;
        } else if (key == Arcade::Keys::UP) {
            this->lib_count--;
        }
        if (this->lib_count == -1)
            this->lib_count = 4;
        if (this->lib_count == 5)
            this->lib_count = 0;
        return this->lib_count;
    }

    void NCURSES::refresh()
    {
        wrefresh(this->win);
    }

    void NCURSES::closeWindow()
    {
        delwin(this->win);
        endwin();
    }

    std::string NCURSES::getName() const
    {
        return "NCURSES";
    }

}
