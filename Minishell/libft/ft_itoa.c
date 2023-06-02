/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:31 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:28:37 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_index(int n)
{
	if (n <= 0)
		return (1);
	return (0);
}

static long	make_positive(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	len(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	i;

	nbr = n;
	i = my_index(nbr);
	nbr = make_positive(nbr);
	i += len(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	*(str + i--) = '\0';
	while (nbr > 0)
	{
		*(str + i--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (i == 0 && str[1] == '\0')
		*(str + i) = '0';
	else if (i == 0 && str[1] != '\0')
		*(str + i) = '-';
	return (str);
}
