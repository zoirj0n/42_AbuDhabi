/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:33:48 by zosobiro          #+#    #+#             */
/*   Updated: 2022/06/17 00:30:42 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (dest == source || !n)
	{
		return (dest);
	}
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// int main ()
// {
// 	char m[6]= "hello";
// 	char n[7];
// 	char *p;
// 	printf("%s",ft_memcpy(n,m,7));
// }