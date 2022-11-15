<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:07:53 by zosobiro          #+#    #+#             */
/*   Updated: 2022/10/05 01:12:12 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_left_string(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;
=======

#include "get_next_line_bonus.h"

char *ft_read_to_left_str(int fd, char *left_str)
{
	char *buff;
	int rd_bytes;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
<<<<<<< HEAD
	while (!ft_stringchar(left_str, '\n') && rd_bytes != 0)
=======
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

<<<<<<< HEAD
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_string(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_string(left_str[fd]);
=======
char *get_next_line(int fd)
{
	char *line;
	static char *left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line 1: %s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line 2: %s", line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line 3 %s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
