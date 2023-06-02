/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:29:10 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:29:11 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*crs;
	char	*dest;

	crs = (char *)src;
	dest = (char *)dst;
	if (crs < dest)
	{
		while (len--)
		{
			dest[len] = crs[len];
		}
	}
	else
		ft_memcpy(dest, crs, len);
	return (dst);
}
