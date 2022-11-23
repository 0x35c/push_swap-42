# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/11/21 21:15:10 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = parsing.c main.c check_format.c instructions_1.c instructions_2.c sort.c\

CC = clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

OBJ = $(SRC:.c=.o)

all: ${NAME}

makelibft:
	make re -C ./libft

${NAME}: makelibft ${OBJ}
	$(CC) -o ${NAME} $(OBJ) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ${NAME} 

re: all clean

.PHONY: all clean fclean re
