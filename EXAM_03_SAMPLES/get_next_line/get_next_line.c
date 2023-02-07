/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:29:51 by zosobiro          #+#    #+#             */
/*   Updated: 2023/02/07 15:30:11 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*string = malloc(10000), *buffer = string;
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return (buffer > string) ? (*buffer = 0, string) : (free(string), NULL);
}