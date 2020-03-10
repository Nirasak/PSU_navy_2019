##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/my_strcmp.c	\
		src/connect.c	\
		src/create_map.c	\
		src/print_map.c	\
		src/get_next_line.c	\
		src/fill_map.c	\
		src/my_atoi.c	\
		src/init.c	\
		src/navy.c	\
		src/get_attack.c	\
		src/signal.c	\
		src/game_end.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

LDFLAGS	=	-L ./ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
