# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/12/12 18:53:51 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/parsing.c src/main.c src/check_format.c src/instructions_1.c\
	  src/instructions_2.c src/sort.c src/utils.c src/normalize.c src/algo.c\
	  src/algo_utils.c src/lst_utils.c\

CC = clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft
	$(CC) ${OBJ} -o ${NAME} $(LIBS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re
