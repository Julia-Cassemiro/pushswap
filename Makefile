# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:02:26 by jgomes-c          #+#    #+#              #
#    Updated: 2022/02/03 15:02:26 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src/
P_UTI = ./src/utils/
P_MOV = ./src/movements/
P_LIBFT = ./includes/libft/
P_OBJ = ./obj/
P_INCLUDE = ./includes/

FILES = $(P_SRC)main.c $(P_UTI)utils0.c $(P_UTI)utils1.c \
		$(P_MOV)move_ss.c $(P_MOV)move_rr.c
		
SRC = $(patsubst $(P_SRC)%.c, $(P_OBJ)%.o, $(FILES))

LIBFT = $(P_LIBFT)libft.a
NAME = push_swap

CC = gcc
RM = rm -rf
RMR = rm -rf
CFLAGS = -Wall -Werror -Wextra -I ./include/ -g #-fsanitize=address

all: $(NAME)

$(NAME): $(SRC)
	@make --no-print-directory -C $(P_LIBFT)
	@echo Folder for obj Created.
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "file(push_swap) created."

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(P_OBJ)
	@mkdir -p $(P_OBJ)utils
	@mkdir -p $(P_OBJ)movements
	@$(CC) $(CFLAGS) -I. -c $< -o $@

#VALGRIND--|
val:
	valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes --log-file=valgrind-out.txt ./$(NAME) $(a)

clean:
	@$(RM) $(P_OBJ)
	@make clean --no-print-directory -C $(P_LIBFT)
	@rm -f valgrind-out.txt
	@echo All clean.

fclean: clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C $(P_LIBFT)

re: fclean all