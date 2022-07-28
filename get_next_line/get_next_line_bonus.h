
#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *ft_read_to_left_str(int fd, char *left_str);
char *ft_strchr(char *s, int c);
size_t ft_strlen(char *s);
char *ft_strjoin(char *left_str, char *buff);
char *ft_get_line(char *left_str);
char *ft_new_left_str(char *left_str);

#endif
