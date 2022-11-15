/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:33:37 by zosobiro          #+#    #+#             */
/*   Updated: 2022/06/12 18:33:43 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	cs;

	i = 0;
	str = (char *)s;
	cs = (unsigned char)c;
	while (i < n)
	{
		if (cs == str[i])
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
//     char t[6] = {'h','e','l','l','o'};
//     char *p = ft_memchr(t, 'e', 6);
//     printf("%s", p);
// }
// s	pointer
// c int  111 '0'
// n	size_t = 6
// i	 size_t =4
// str		pointer
// cs	char  'o'
// bu yerda bizga o ni qidiryabdi