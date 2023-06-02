/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:47 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:21 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dup2(t_cmd2 *commands, int fd_in, int fd_out)
{
	if (fd_out > 1)
	{
		if (dup2(fd_out, STDOUT_FILENO) < 0)
			ft_putstr_fd("writing  file failed\n", 2);
	}
	else if (commands->next != NULL)
	{
		if (dup2(commands->fd[1], STDOUT_FILENO) < 0)
			ft_putstr_fd("writing1 failed to pipe\n", 2);
	}
	if (fd_in > 0)
	{
		if (dup2(fd_in, STDIN_FILENO) < 0)
			ft_putstr_fd("reading  file failed\n", 2);
	}
	else if (commands->prev)
	{
		if (dup2(commands->prev->fd[0], STDIN_FILENO) < 0)
			ft_putstr_fd("writing2 failed to pipe\n", 2);
	}
}
