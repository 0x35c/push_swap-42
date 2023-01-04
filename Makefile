# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2023/01/02 22:07:17 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/parsing.c src/main.c src/check_format.c src/check_list.c\
	  src/instructions_1.c src/instructions_2.c src/low_sort.c src/normalize.c\
	  src/algo.c src/algo_utils.c src/lst_utils.c src/utils.c\

CC = @clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ./libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'
	$(CC) ${OBJ} -o ${NAME} $(LIBS)
	@printf '\x1b[38;2;50;205;50mPush Swap compiled 🤓\n\x1b[0m'

clean:
	@rm -f $(OBJ)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mObjects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean: clean
	@rm -f ${NAME} 
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBinary removed\x1b[0m\e[5m 🚨\n\e[0m'

re: fclean all

.PHONY: all clean fclean re
