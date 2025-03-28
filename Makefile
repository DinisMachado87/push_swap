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
SRC_2		= srcs/push_swap/stack_utils.c
SRC_3		= srcs/push_swap/lis.c \
			  srcs/push_swap/find_max_subsequences.c
SRC_4		= srcs/push_swap/operations/swap.c \
			  srcs/push_swap/operations/push.c \
			  srcs/push_swap/operations/rotate.c
SRC_tests	= srcs/push_swap/print_stack.c \
			  srcs/push_swap/tests.c 

OBJ_1		= ${SRC_1:.c=.o}
OBJ_2		= ${SRC_2:.c=.o}
OBJ_3		= ${SRC_3:.c=.o}
OBJ_4		= ${SRC_4:.c=.o}
OBJ_tests	= ${SRC_tests:.c=.o}

DEBUG_OBJ_1	= ${SRC_1:.c=_debug.o}
DEBUG_OBJ_2	= ${SRC_2:.c=_debug.o}
DEBUG_OBJ_3	= ${SRC_3:.c=_debug.o}
DEBUG_OBJ_4	= ${SRC_4:.c=_debug.o}
DEBUG_OBJ_tests	= ${SRC_tests:.c=_debug.o}

INCLUDE		= -L ./libft -lft

.c.o:
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ_1} ${OBJ_2} ${OBJ_3} ${OBJ_4} ${OBJ_tests}

	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} ${OBJ_3} ${OBJ_4} ${OBJ_tests} -o ${NAME} ${INCLUDE}

debug: ${DEBUG_NAME}

${DEBUG_NAME}: ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3} ${DEBUG_OBJ_4} ${DEBUG_OBJ_tests}
	make -C $(LIBFTDIR)
	${CC} ${DEBUG_FLAGS} ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3} ${DEBUG_OBJ_4} ${DEBUG_OBJ_tests} -o ${DEBUG_NAME} ${INCLUDE}

srcs/push_swap/%_debug.o: srcs/push_swap/%.c
	${CC} ${DEBUG_FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${OBJ_3} ${OBJ_4} ${OBJ_tests} ${DEBUG_OBJ_1} ${DEBUG_OBJ_2} ${DEBUG_OBJ_3} ${DEBUG_OBJ_4} ${DEBUG_OBJ_tests} ${NAME} ${DEBUG_NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${DEBUG_NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re debug

