# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 21:30:14 by ivaliev           #+#    #+#              #
#    Updated: 2023/02/17 21:30:15 by ivaliev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEADER	= .

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

RM		= rm -f

GCCF = gcc -Wall -Wextra -Werror -g

LIB = ar -rcs

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \
		ft_strcmp.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c

all:	${NAME}

.c.o:
		@printf "\033[A\033[2K\r"
		@${GCCF} -c $< -o ${<:.c=.o} -I $(HEADER)

$(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

bonus: ${OBJSBONUS}
		@${LIB} ${NAME} ${OBJSBONUS}

clean:
		@${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all