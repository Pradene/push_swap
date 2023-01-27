# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpradene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:33:43 by lpradene          #+#    #+#              #
#    Updated: 2022/12/12 21:35:10 by lpradene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= check.c \
		init.c \
		lst.c \
		push.c \
		push_swap.c \
		reverse_rotate.c \
		rotate.c \
		sort2.c \
		sort3.c \
		sort5.c \
		swap.c \
		utils.c \
		main.c \

SRCS = ${addprefix src/, ${FILES}}

CC		= cc

FLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

OBJS	= ${SRCS:.c=.o}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean clean all
