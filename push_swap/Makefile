# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 20:35:35 by zosobiro          #+#    #+#              #
#    Updated: 2023/01/03 20:39:08 by zosobiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ./src/push_swap.c ./src/instructions.c ./src/instructions_2.c ./src/ft_push1.c \
	  ./src/instructions_3.c ./src/check.c ./src/push_swap_utils3.c ./src/push_swap_utils_2.c ./src/push_swap_utils.c ./src/sort_functions.c


SRC_BONUS = ./bonus/checker_utils.c ./bonus/checker_utils2.c ./bonus/checker.c ./bonus/instructions_checker_2.c ./bonus/instructions_checker_3.c ./bonus/instructions_checker.c ./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)


bonus: $(NAME_BONUS) $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft -o $(NAME_BONUS)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "Objects Removed !"
	
fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Binary Removed !"

re: fclean all