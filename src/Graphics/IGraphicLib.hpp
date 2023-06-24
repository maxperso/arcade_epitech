/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

/*
* Interface used by graphic libraries
* All functions must be implemented correctly for the kernel to handle the graphic libraries.
*/

#pragma once

#include <string>
#include "../include/Keys.hpp"
#include "../include/Assets.hpp"


namespace Arcade {
	/*!
	 * @namespace Arcade
	 * @brief Arcade project namespace
	 */

	class IGraphicLib {
		//Purely virtual class that serves as the basis for all graphic libraries
	public:
		
		virtual ~IGraphicLib() = default;
		// Destructor
		//IGraphicLib class's destructor

		virtual std::string getName() const = 0;
		//summary: Graphic library name's getter
		//return: a string containing the name of the graphic library

		virtual void popWindow(std::string const& title, int width, int height) = 0;
		//summary: Creates a window
		//param title: the title of the window
		//return: void

		virtual Keys getLastEvent() = 0;
		//summary: Gets the last keyboard event that happened in the window
		//return: the last event that happened in the window

		virtual void mapManager(Assets &a, int x, int y) = 0;
		//summary: displays different sprites at the x and y position
		//param a: the assets to use
		//param x: the x position of the map
		//param y: the y position of the map

		virtual void drawText(std::string text, int x, int y) = 0;
		//summary: Draws text
		//param lib:the text to draw, the x and y coordinates

		virtual void closeWindow() = 0;
		//summary: Closes the window

		virtual int select(Arcade::Keys key) = 0;
		//summary: Selects the current item in the menu

		virtual void refresh() = 0;
		//summary: Refreshes the window
	};
};
