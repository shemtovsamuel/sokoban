##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## build project
##

SRC = 	sources/main.c \
		sources/lib.c \
		sources/check.c \
		sources/key.c \
		sources/management_map.c \
		sources/management_pos.c \
		sources/util.c \
		sources/check2.c\
		sources/nb.c\

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

CFLAGS += -I./ -Wall

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) -lcsfml-audio $(OBJ) -lncurses -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re
