/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-mathis.legrand
** File description:
** main
*/

#include <iostream>
#include <string.h>
#include "Core/Arcade.cpp"

int main (int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error: no library path given" << std::endl;
        return (84);
    }

    try {
        Arcade::Arc arc;
        arc.run(av[1], arc.menu_path);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }

    return (0);
}
