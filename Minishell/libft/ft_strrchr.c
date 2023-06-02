/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:29:57 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:29:58 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len - 1] == (unsigned char)c)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}
