NAME = philo
SRC = philo.c philo_utils.c start_prog.c initialize.c check_done_eat_and_die.c routine.c
OBJS = $(SRC:.c=.o)
CC = gcc -pthread
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -lpthread ${CFLAGS} ${OBJS} -o $@

%.o: %.c philosophers.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all