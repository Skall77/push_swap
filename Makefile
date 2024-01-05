# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 19:04:49 by aaudevar          #+#    #+#              #
#    Updated: 2022/11/20 19:04:49 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC = ./srcs/

DIRCINC = ./includes/

DIRLIB = ./libft/

SRC =  ft_push_swap \
	   utils \
	   utils_2 \
	   parsing \
	   instructions \
	   instructions2 \
	   instructions3 \
	   search \
	   sort \
	   arrays \
	   sorting \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = ${SRCS:.c=.o}

NAME = push_swap
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
TEST100= ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $$ARG | ./checker_linux $$ARG
TEST500= ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` ; ./push_swap $$ARG | ./checker_linux $$ARG
TEST100WC= ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $$ARG | wc -l
TEST500WC= ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` ; ./push_swap $$ARG | wc -l

.c.o:
	${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	cd ${DIRLIB} && ${MAKE}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L./libft -lft

all: ${NAME}

clean:
	${RM} ${OBJS}
	cd ${DIRLIB} && ${MAKE} clean

fclean: clean
	${RM} ${NAME}
	cd ${DIRLIB} && ${MAKE} fclean

test100: ${NAME}
	${TEST100}

test500: ${NAME}
	${TEST500}

test100wc: ${NAME}
	${TEST100WC}

test500wc: ${NAME}
	${TEST500WC}

re : fclean all

.PHONY : all clean fclean re