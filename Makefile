##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile du Day 10, accessoirement la Task 1
##

SRC =	main.c	\
		Looper.c	\
		Entities.c	\
		Init.c	\
		input.c	\
		dog.c	\
		green_mid_duck.c	\
		pink_mid_duck.c	\
		RL_duck.c	\
		animation.c	\
		clean.c	\
		bullet.c	\
		IGstats.c	\
		Menu.c	\

OBJ =	$(SRC:.c=.o)

NAME =	my_hunter

INC = -I./include

LIB = -L./lib/my -lmy

CSFML = -l csfml-graphics -l csfml-audio -l csfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(INC) $(LIB) $(CSFML)
			rm -f $(OBJ)
			clear

exe:		$(NAME)
			clear
			./$(NAME)

clean: 
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f lib/my/libmy.a

re: fclean all

usage:	$(NAME)
		./$(NAME) -h
