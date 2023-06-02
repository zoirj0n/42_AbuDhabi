/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:29:16 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:29:17 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	putchar(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
		}
		ft_putchar_fd(48 + nb % 10, fd);
	}
}
