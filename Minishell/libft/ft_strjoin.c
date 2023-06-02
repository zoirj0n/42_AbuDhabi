/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:29:32 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:29:33 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// char	*ft_customjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (NULL);
// 	while (s1 && s1[i] != '\0')
// 	{
// 		*(str + i) = *(s1 + i);
// 		i++;
// 	}
// 	while (s2 && s2[j] != '\0')
// 	{
// 		*(str + i) = *(s2 + j);
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// 	free(s1);
// 	s1 = NULL;
// 	return (str);
// }
