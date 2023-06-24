/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

/*
* Interface used by game libraries.
* All functions must be implemented correctly for the kernel to handle the game libraries.
*/

#pragma once

#include "../Graphics/IGraphicLib.hpp"
#include "../include/Assets.hpp"
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

namespace Arcade {
	/*!
	 * @class IGameLib
	 * @brief Game libraries virtual class
	 */

	class IGameLib {
		// Purely virtual class that serves as the basis for all game libraries
	public:

		virtual ~IGameLib() = default;
		// Destructor
		// IGameLib class's destructor

		virtual std::string getName() const = 0;
		//summary: Game name's getter
		//return: a string containing the name of the game
		virtual bool init(Arcade::IGraphicLib &lib) = 0;
		//summary: Initializes the game
		//param lib: the graphic library to use
		//return: true if the game was initialized correctly, false otherwise

		virtual void map_creator(Arcade::IGraphicLib &lib) = 0;
		//summary: Creates the map
		//param lib: the graphic library to use

		virtual void directions_assigner(Arcade::Keys key) = 0;
		//summary: Assigns the directions to the snake
		//param key: the key pressed by the user

		virtual void collisions() = 0;
		//summary: Checks for collisions

		virtual void drawSnake(Arcade::IGraphicLib &lib, int snake_body_x, int snake_body_y) = 0;
		//summary: Draws the snake
		//param lib: the graphic library to use and the snake's body's coordinates

		virtual void end_game_score(Arcade::IGraphicLib &lib) = 0;
		//summary: Displays the score at the end of the game
		//param lib: the graphic library to use

		virtual void change_libs(Arcade::IGraphicLib &lib, Arcade::Keys key) = 0;
		//summary: Changes the .so file of the graphic or game libraries
		//param lib: the graphical interface to use

	};
};
