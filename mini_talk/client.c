/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:59:44 by zosobiro          #+#    #+#             */
/*   Updated: 2023/04/06 20:05:27 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(char c, int pid)
{
	int	i;
	int	j;

	i = 128;
	j = 0;
	(void)pid;
	while (i > 0)
	{
		if ((c & i) == i)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		i = i / 2;
		usleep(150);
	}
	ft_error("", j);
}

int	main(int ac, char **av)
{
	int	a;
	int	i;

	i = 0;
	if (ac == 3)
	{
		a = ft_atoi(av[1]);
		while (av[2][i])
			send_data(av[2][i++], a);
		send_data('\0', a);
	}
	else
		write(1, "Error : Format ./client <server_pid> <message>\n", 48);
}
