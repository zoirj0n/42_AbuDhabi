# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 21:32:18 by ivaliev           #+#    #+#              #
#    Updated: 2023/02/17 21:32:19 by ivaliev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-fsanitize=address

NAME	= minishell
#CC      = gcc -fsanitize=address
CC      = gcc
CFLAGS   = -Wall -Wextra -Werror -g  -I/usr/local/opt/readline/include

SRCDIR   = srcs
OBJDIR   = srcs

# OK_COLOR = \x1b[32;01m
OK_COLOR = \033[0;31m
COLOUR_END =\033[0m

SOURCES  =	main.c parsing/ft_parser.c parsing/ft_lexer.c parsing/ft_token.c\
			parsing/ft_quotes.c parsing/ft_convert.c parsing/ft_word.c\
			parsing/ft_pipes.c parsing/ft_make_cmds.c parsing/ft_cmd.c\
			parsing/ft_helpers.c parsing/ft_cmd2.c parsing/ft_make_cmds2.c\
			parsing/ft_comd.c parsing/ft_allput.c\
			parsing/ft_redirs.c parsing/ft_word_1.c parsing/ft_word_2.c\
			parsing/ft_word_3.c parsing/ft_word_4.c parsing/ft_allput_1.c\
			parsing/ft_cmd_1.c parsing/ft_helpers_1.c parsing/ft_destroyers.c\
			parsing/ft_convert_1.c parsing/ft_convert_2.c\
			parsing/ft_convert_3.c parsing/ft_convert_4.c parsing/ft_convert_5.c\
			parsing/ft_convert_1_1.c\
			builtins/ft_echo.c builtins/ft_env.c ft_copy_env.c builtins/ft_unset.c\
			builtins/ft_export.c builtins/ft_cd.c builtins/ft_pwd.c\
			exec/ft_multiple_pipes.c list_utils.c builtins/ft_export_helper.c\
			exec/ft_forked_builtin.c exec/normal_commands_exec.c exec/ft_dup2.c\
			exec/convert_list_2array.c exec/error.c exec/ft_builtin.c exec/open_close.c\
			exec/ft_heredoc.c ft_free.c exec/open_close_pipes.c exec/ft_expr.c\
			builtins/ft_exit.c exec/ft_get_real_path.c

INCLUDES = libft/libft.h minishell.h

OBJECTS  = $(SOURCES:%.c=%.o)
rm = rm -f

all: $(NAME)

party:
	make all
	
$(OBJECTS): %.o : %.c $(INCLUDES)
#	@printf "\033[A\033[2K\r"
	$(CC) -c $< -o $@ $(CFLAGS) 

$(NAME): $(OBJECTS)
	@$(MAKE) -C libft
	@$(CC) -o $@ $^ $(CFLAGS) -L libft -L/usr/local/opt/readline/lib -lreadline libft/libft.a
	@echo "$(OK_COLOR)$(NAME)"
clean:
	@rm -f $(OBJECTS)
	@$(MAKE) fclean -C libft

fclean: clean
	@rm -f $(NAME)
	@echo "$(OK_COLOR) full clean"
re: fclean all

.PHONY: all clean fclean re
