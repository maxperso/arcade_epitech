# Arcade
Arcade is a gaming platform, a program that lets the user choose a game to play and keeps a register of player scores.

## Requirements

`Build`
- C++20 compiler
- cmake 3.17

`Libraries`
- SFML
- SDL
- SDL_image
- SDL_mixer
- SDL_ttf
- NCURSES

## Build

```
make re
```

## Librairies
### Graphic
We include `3` graphic libs:   
- SFML
- SDL
- NCURSES   

### Game
We include `2` game libs:
- Nibbler
- Snake

## Usage
```bash
USAGE:
  ./arcade path_to_graphical_lib
  
DESCRIPTION:
  lib         path to the initial graphical library to load (./lib/arcade_lib_name.so)
  
COMMANDS:
  N           next graphic lib
  P           previous graphic lib
  O           next game lib
  I           previous game lib
  
  M           menu
  R           reset the game
  ESC         quit arcade
  
  RIGHT_ARROW move right
  LEFT_ARROW  move left
  UP_ARROW    move up
  DOWN_ARROW  move down
```