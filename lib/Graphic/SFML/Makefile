##
## EPITECH PROJECT, 2022
## Makefile
## File description:
##

SRC    =   src/SFML.cpp
OBJ    =   $(SRC:.cpp=.o)
NAME   =   arcade_sfml.so

CC      =   g++
CFLAGS  =   -fPIC `sdl2-config --cflags`
LDFLAGS =   -shared -lsfml-graphics -lsfml-window -lsfml-system
RM      =   rm -rf

all:    $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):   $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

