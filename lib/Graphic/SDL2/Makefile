##
## EPITECH PROJECT, 2022
## Makefile
## File description:
##

SRC    =   src/SDL2.cpp

OBJ    =   $(SRC:.cpp=.o)

NAME   =   arcade_sdl2.so

CC      =   g++
CFLAGS  =   -fPIC `sdl2-config --cflags`
LDFLAGS =   -shared `sdl2-config --libs` -lSDL2_ttf
RM      =   rm -rf

all:    $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):   $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
