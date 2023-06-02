/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:08 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:45 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_pipes(t_cmd2 *commands, int nb_cmd)
{
	while (commands && commands->prev)
		commands = commands->prev;
	while (commands && nb_cmd > 1)
	{
		close(commands->fd[0]);
		close(commands->fd[1]);
		commands = commands->next;
	}
}

void	ft_open_pipes(t_cmd2 **commands)
{
	t_cmd2	*tmp;

	tmp = *commands;
	while (tmp)
	{
		if (pipe(tmp->fd) == -1)
			(strerror(errno));
		tmp = tmp->next;
	}
}
