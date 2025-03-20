# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:08:24 by dimachad          #+#    #+#              #
#    Updated: 2025/03/20 20:20:05 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
RM		= rm -f
FLAGS	= -Wall -Werror -Wextra
LIBFTDIR	= libft/
SRC_DIR	= srcs/

SRC_1	= srcs/push_swap/push_swap.c

SRC_2	= srcs/push_swap/node_utils.c

OBJ_1	= ${SRC_1:.c=.o}
OBJ_2	= ${SRC_2:.c=.o}

INCLUDE	= -L ./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re

