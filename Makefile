##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

# (ne pas supprimer)
# $(shell mkdir "lib")
# $(shell mkdir "lib/games")
# $(shell mkdir "lib/libraries")

CXX		=	g++

INC		=	-I src/

CXXFLAGS	+=	-Wall -Wextra -pedantic -std=c++20 -fPIC $(INC) -g3

LDFLAGS		=	-ldl

## arcade

NAME		=	arcade

SRC		=	src/main.cpp

# src/Core/Loader/loader.cpp
# src/Core/Arcade.cpp
# src/LibraryLoader.cpp
# src/Error.cpp

OBJ		=	$(SRC:.cpp=.o)

## plugin sfml

NAME_SFML	=	lib/arcade_sfml.so

SRC_SFML    =	src/Graphics/SFML/SFML.cpp

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

LDFLAGS_SFML	=	-shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

# plugin sdl

NAME_SDL	=	lib/arcade_sdl2.so

SRC_SDL		=	src/Graphics/SDL/SDL.cpp

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image

# plugin ncurses

NAME_NCURSES	= 	lib/arcade_ncurses.so

SRC_NCURSES		=	src/Graphics/NCURSES/NCurses.cpp

OBJ_NCURSES		=	$(SRC_NCURSES:.cpp=.o)

LDFLAGS_NCURSES	=	-shared -fPIC -lncurses

## snake

NAME_SNAKE	=	lib/arcade_snake.so

SRC_SNAKE	=	src/Games/Snake/Snake.cpp

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

LDFLAGS_SNAKE	=	-shared -fPIC

## nibbler

NAME_NIBBLER	=	lib/arcade_nibbler.so

SRC_NIBBLER	=	src/Games/Nibbler/Nibbler.cpp

OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)

LDFLAGS_NIBBLER	=	-shared -fPIC

## menu

NAME_MENU	=	lib/arcade_menu.so

SRC_Menu	=	src/Games/Menu/Menu.cpp

OBJ_MENU	=	$(SRC_Menu:.cpp=.o)

LDFLAGS_MENU	=	-shared -fPIC

all:			core games graphicals

core:			$(NAME)

games:			$(NAME_NIBBLER) $(NAME_SNAKE) $(NAME_MENU)

graphicals:		$(NAME_SFML) $(NAME_SDL) $(NAME_NCURSES)

$(NAME_SFML):		$(OBJ_SFML)
			$(CXX) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)

$(NAME_SDL):		$(OBJ_SDL)
			$(CXX) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

$(NAME_NCURSES):	$(OBJ_NCURSES)
			$(CXX)	$(OBJ_NCURSES) -o $(NAME_NCURSES) $(LDFLAGS_NCURSES)

$(NAME_NIBBLER):		$(OBJ_NIBBLER)
			$(CXX) $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(LDFLAGS_NIBBLER)

$(NAME_SNAKE):		$(OBJ_SNAKE)
			$(CXX) $(OBJ_SNAKE) -o $(NAME_SNAKE) $(LDFLAGS_SNAKE)

$(NAME_MENU):		$(OBJ_MENU)
			$(CXX) $(OBJ_MENU) -o $(NAME_MENU) $(LDFLAGS_MENU)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJ_SFML) $(OBJ_NIBBLER) $(OBJ_SNAKE) $(OBJ) $(OBJ_SDL) $(OBJ_NCURSES) $(OBJ_MENU)

fclean:			clean
			$(RM) $(NAME_SFML) $(NAME_NIBBLER) $(NAME_SNAKE) $(NAME) $(NAME_SDL) $(NAME_NCURSES) $(NAME_MENU)

re:			fclean all

.PHONY:		clean fclean re all