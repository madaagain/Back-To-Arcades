##
## EPITECH PROJECT, 2022
## Makefile
## File description:
##

SRC    =   src/ATetris.cpp

OBJ    =   $(SRC:.cpp=.o)

NAME = arcade_tetris.so

CC  =   g++
CFLAGS = -fPIC
LDFLAGS = -shared
RM = rm -rf

all:    $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):   $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
