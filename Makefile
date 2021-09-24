# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 18:45:26 by eerika            #+#    #+#              #
#    Updated: 2021/09/23 14:52:15 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex.a
PROG	= pipex

SRCS 	= 	srcs/pipex.c srcs/execute.c srcs/free_array.c\
			srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_copy.c \
			srcs/ft_error.c srcs/ft_join.c srcs/ft_putstr.c \
			srcs/ft_split.c srcs/ft_strcmp.c srcs/ft_strlen.c \
			srcs/ft_strncmp.c 
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= 	srcs/pipex_bonus.c srcs/exec_bonus.c srcs/free_array.c \
			srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_copy.c \
			srcs/ft_error.c srcs/ft_join.c srcs/ft_putstr.c \
			srcs/ft_split.c srcs/ft_strcmp.c srcs/ft_strlen.c \
			srcs/ft_strncmp.c srcs/get_next_line.c \
			srcs/get_next_line_utils.c

OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

CC 		= gcc
CFLAGS 	= -g -Wall -Wextra -Werror

.c.o:		%.o : %.c
					@gcc ${CFLAGS}  -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) $(NAME) ${MAIN} -o ${PROG}

all: 		${NAME}

bonus:		${OBJS_B}
					@ar -rcs ${NAME} ${OBJS_B}
					@$(CC) $(NAME) ${MAIN_B} -o ${PROG}

clean:
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re bonus