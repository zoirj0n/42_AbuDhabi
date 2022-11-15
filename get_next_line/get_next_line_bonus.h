<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:39:00 by zosobiro          #+#    #+#             */
/*   Updated: 2022/10/19 02:03:12 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 42
// #endif

char	*get_next_line(int fd);
char	*ft_read_to_left_string(int fd, char *left_str);
char	*ft_stringchar(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_new_left_string(char *left_str);
=======

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
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

#endif
