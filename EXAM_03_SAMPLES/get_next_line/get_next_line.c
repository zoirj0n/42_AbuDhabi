/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:29:51 by zosobiro          #+#    #+#             */
/*   Updated: 2023/02/08 15:02:17 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*string = malloc(10000), *buffer = string;
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return (buffer > string) ? (*buffer = 0, string) : (free(string), NULL);
}

// #include <unistd.h>
// #include <stdlib.h>

// char	*get_next_line(int fd)
// {
// 	int		rd = 0;
// 	char	c;
// 	char	*line = malloc(100000);
// 	char	*word = line;
// 	if ((rd = read(fd, &c, 1)) == 0)
// 		return (NULL);
// 	*line++ = c;
// 	while ((rd = read(fd, &c, 1)) > 0 && c != '\n')
// 		*line++ = c;
// 	if (c == '\n')
// 		*line++ = '\n';
// 	*line = '\0';
// 	return (word);
// }

// #include <stdio.h>
// int main() // main1.c
// {
// 	char *line;
// 	line = get_next_line(0);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = get_next_line(0);
// 	}
// 	return (0);
// }
