# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 19:28:19 by jgomes-c          #+#    #+#              #
#    Updated: 2022/01/27 19:28:19 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_bzero.c ft_strlen.c ft_calloc.c ft_putendl_fd.c 
SRC = $(FILES:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(SRC)
	@ar -rcs $(NAME) $(SRC)

$(SRC): $(FILES)
	@$(CC) $(FLAGS) -c $(FILES)

clean:
	@$(RM) $(SRC)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

