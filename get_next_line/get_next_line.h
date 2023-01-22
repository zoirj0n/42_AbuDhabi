/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:49:40 by zosobiro          #+#    #+#             */
/*   Updated: 2022/11/15 12:49:41 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

char *get_next_line(int fd);
char *ft_read_to_left_str(int fd, char *left_str);
char *ft_strchr(char *s, int c);
char *ft_strjoin(char *left_str, char *buff);
size_t ft_strlen(char *s);
char *ft_get_line(char *left_str);
char *ft_new_left_str(char *left_str);

#endif
