# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 16:39:37 by eerika            #+#    #+#              #
#    Updated: 2021/06/10 16:55:03 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc -g

SRCDIR=src
HEADDIR=include

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror

SRC=$(SRCDIR)/pipex.c\
	$(SRCDIR)/path_treat.c\
	$(SRCDIR)/ft_split.c\
	$(SRCDIR)/ft_strncmp.c\
	$(SRCDIR)/ft_strlen.c\
	$(SRCDIR)/ft_strjoin.c\
	$(SRCDIR)/execution.c\
	$(SRCDIR)/ft_putstr.c\

OBJ = $(SRC:.c=.o)

NAME=pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -o $@ -c $<

clean :
	rm -rf $(SRCDIR)/*.o

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean