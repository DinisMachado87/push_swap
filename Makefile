# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 15:08:24 by dimachad          #+#    #+#              #
#    Updated: 2025/03/24 15:33:13 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
DEBUG_NAME	= push_swap_debug
CC			= cc
RM			= rm -f
FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -Wall -Werror -Wextra -g -O0
LIBFTDIR	= libft/
SRC_DIR		= srcs/

SRC_1		= srcs/push_swap/push_swap.c
SRC_2		= srcs/push_swap/node_utils.c
SRC_3		= srcs/push_swap/lis.c \
			  srcs/push_swap/find_max_subsequences.c \

OBJ_1		= ${SRC_1:.c=.o}
OBJ_2		= ${SRC_2:.c=.o}
OBJ_3		= ${SRC_3:.c=.o}

DEBUG_OBJ_1	= ${SRC_1:.c=_debug.o}
DEBUG_OBJ_2	= ${SRC_2:.c=_debug.o}
DEBUG_OBJ_3	= ${SRC_3:.c=_debug.o}

INCLUDE		= -L ./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ_1} ${OBJ_2} ${OBJ_3}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} ${OBJ_3} -o ${NAME} ${INCLUDE}

debug: ${DEBUG_NAME}

${DEBUG_NAME}: ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3}
	make -C $(LIBFTDIR)
	${CC} ${DEBUG_FLAGS} ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3} -o ${DEBUG_NAME} ${INCLUDE}

srcs/push_swap/%_debug.o: srcs/push_swap/%.c
	${CC} ${DEBUG_FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${OBJ_3} ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3} ${NAME} ${DEBUG_NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${DEBUG_NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re debug

