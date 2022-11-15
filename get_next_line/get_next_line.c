<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:08:36 by zosobiro          #+#    #+#             */
/*   Updated: 2022/10/19 02:03:24 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_left_string(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;
=======
#include "get_next_line.h"

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
	while (ft_stringchar(left_str, '\n') == 0 && rd_bytes != 0)
=======
	while (ft_strchr(left_str, '\n') == 0 && rd_bytes0 != 0)
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
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_string(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_string(left_str);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int	fd1;

// 	fd1 = open("test/test.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("line 1: %s\n", line);
// 	line = get_next_line(fd1);
// 	printf("line 1: %s\n", line);
// 	line = get_next_line(fd1);
// 	printf("line 1: %s\n", line);
// 	close(fd1);
// 	return (0);
// }
=======
char *get_next_line(int fd)
{
	char *line;
	static char *left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

int main(void)
{
	char *line;
	int fd1;

	fd1 = open("test/test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("line 1: %s\n", line);
	line = get_next_line(fd1);
	printf("line 1: %s\n", line);
	line = get_next_line(fd1);
	printf("line 1: %s\n", line);
	close(fd1);
	return (0);
}
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff
