##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiler script
##

SRC     =   main.cpp \
            Core/src/Core.cpp \

OBJ     =   $(SRC:.cpp=.o)

NAME    =   arcade

CPPFLAGS =

RM = rm -rf
	
all:    $(NAME)
		$(MAKE) -C lib/Graphic/NCURSES
		$(MAKE) -C lib/Graphic/SFML
		$(MAKE) -C lib/Graphic/SDL2
		$(MAKE) -C lib/Games/Tetris
		$(MAKE) -C lib/Games/Snake	

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean:     clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(MAKE) -C lib/Graphic/NCURSES fclean
	$(MAKE) -C lib/Graphic/SFML fclean
	$(MAKE) -C lib/Graphic/SDL2 fclean
	$(MAKE) -C lib/Games/Snake fclean
	$(MAKE) -C lib/Games/Tetris fclean


re:     fclean all
