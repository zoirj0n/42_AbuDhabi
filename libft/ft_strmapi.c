/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:34:09 by zosobiro          #+#    #+#             */
/*   Updated: 2022/06/12 18:34:10 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s1;

	if (!s || !f)
		return (NULL);
	s1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s1)
	{
		return (0);
	}
	i = 0;
	while (s[i])
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = 0;
	return (s1);
}

// int main()
// {
// 	printf(ft_strmapi("%s", "545","4"));
// }