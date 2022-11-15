/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:31:46 by zosobiro          #+#    #+#             */
/*   Updated: 2022/10/19 02:03:07 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_string(char *left_str);

#endif
