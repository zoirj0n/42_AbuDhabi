<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:08:22 by zosobiro          #+#    #+#             */
/*   Updated: 2022/10/05 00:56:39 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
=======

#include "get_next_line_bonus.h"

size_t ft_strlen(char *s)
{
	size_t i;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

<<<<<<< HEAD
char	*ft_stringchar(char *s, int c)
{
	int	i;
=======
char *ft_strchr(char *s, int c)
{
	int i;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

<<<<<<< HEAD
char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;
=======
char *ft_strjoin(char *left_str, char *buff)
{
	size_t i;
	size_t j;
	char *str;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

<<<<<<< HEAD
char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;
=======
char *ft_get_line(char *left_str)
{
	int i;
	char *str;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

<<<<<<< HEAD
char	*ft_new_left_string(char *left_str)
{
	int		i;
	int		j;
	char	*str;
=======
char *ft_new_left_str(char *left_str)
{
	int i;
	int j;
	char *str;
>>>>>>> a1abd31497d2d75af38186dfe9efc2fbfe71d7ff

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
