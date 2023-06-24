/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

/*
* Key Enum, each graphics library must store a map in order to convert
* the specific library key code into one of this enum code so that it can be
* used by other components independently of the graphics library.
*/

#pragma once

namespace Arcade {

	enum Keys {
		NONE,
		A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		LEFT, RIGHT, UP, DOWN,
		ENTER, SPACE, DELETE, BACKSPACE, TAB, ESC,
		MOUSELEFT, MOUSERIGHT
	};

	/*!
	 * @enum Keys
	 *
	 * All those keys should be handled by any graphic libraries or any games
	 */
};
