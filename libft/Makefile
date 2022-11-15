# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:34:01 by zosobiro          #+#    #+#              #
#    Updated: 2022/06/14 15:34:04 by zosobiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
LIB = ar -rcs
OBJ = $(SRC:%.c=%.o)
SRC =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_split.c		

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

BONUS_SRC =	ft_lstnew.c			\
			ft_lstadd_back.c	\
			ft_lstlast.c		\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstsize.c


all :$(NAME)

$(NAME) : ${OBJ}
	@${LIB} ${NAME} ${OBJ}

%.o : %.c
	gcc $(FLAGS) -c $^

norme :
	norminette
clean :
	rm -f $(NAME)
fclean : clean
	rm -f *.o
cleano :
	rm -f *.o
re : fclean all

bonus :${BONUS_OBJ}
	@${LIB} ${NAME} ${BONUS_OBJ}
