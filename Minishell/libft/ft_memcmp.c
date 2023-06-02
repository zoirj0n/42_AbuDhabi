/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:29:06 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:29:06 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
			return (((unsigned const char *)s1)[i] -
					((unsigned const char *)s2)[i]);
		i++;
	}
	return (0);
}
