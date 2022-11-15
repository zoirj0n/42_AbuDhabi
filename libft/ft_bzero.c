/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:26:37 by zosobiro          #+#    #+#             */
/*   Updated: 2022/06/14 17:57:39 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int main()
// {
//     char byte[5] = {1, 3, 'f', 2, 0};
//     ft_bzero(byte, 5);
//     int i = 0;
//     while (i < 5)
//     {
//         printf("%d", byte[1]);
//         /* code */
//         i++;
//     }
//     return (0);
// }
// bu bizga hammasini 0 g aaylantiradi
