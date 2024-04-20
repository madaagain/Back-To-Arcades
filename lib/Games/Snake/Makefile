##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-arcade-luan.bourbier
## File description:
## Makefile
##

SRC    =   src/ASnake.cpp

OBJ    =   $(SRC:.cpp=.o)

NAME = arcade_snake.so

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
