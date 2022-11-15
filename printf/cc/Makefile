# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 02:53:17 by zosobiro          #+#    #+#              #
#    Updated: 2022/06/17 02:53:18 by zosobiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIB = ar -rcs

OBJ = $(SRC:%.c=%.o)

SRC = ft_printf.c	ft_printf_utils.c 	ft_print_ptr.c 	ft_print_unsigned.c	 ft_print_hex.c	 ft_itoa.c	 ft_putchar_fd.c

$(NAME) : ${OBJ}
	@${LIB} ${NAME} ${OBJ}


all :	$(NAME)

%.o : %.c
	gcc $(FLAGS) -c $^

clean :
	rm -f $(NAME)

fclean :	clean
	rm -f *.o

re : fclean all
