##
## EPITECH PROJECT, 2023
## maefile
## File description:
## makefile
##

SRC	=	main.c	\
		game_inf.c	\
		game_inf2.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	play

all:	$(NAME)

start: re
	clear
	./$(NAME)

$(NAME): $(OBJ)
	gcc $(SRC) -lncurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

