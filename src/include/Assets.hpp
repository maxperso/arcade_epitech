/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Assets
*/

#ifndef ASSETS_HPP_
#define ASSETS_HPP_

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>

namespace fs = std::filesystem;

struct Assets {
    fs::path image_path;
    fs::path character;
    fs::path color;
    int width;
    int height;
};

#endif /* !ASSETS_HPP_ */
