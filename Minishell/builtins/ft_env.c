/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:24 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:30 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print(t_env *head, int out_fd)
{
	ft_putstr_fd(head->name, out_fd);
	ft_putstr_fd("=", out_fd);
	ft_putstr_fd(head->value, out_fd);
	ft_putstr_fd("\n", out_fd);
}

void	ft_env(t_env *head, int flag, int out_fd)
{
	while (head)
	{
		if (flag == 0 && head->value)
			ft_print(head, out_fd);
		else if (flag == 1)
		{
			ft_putstr_fd("declare -x ", out_fd);
			if (head->value)
			{
				ft_putstr_fd(head->name, out_fd);
				ft_putstr_fd("=\"", out_fd);
				ft_putstr_fd(head->value, out_fd);
				ft_putstr_fd("\"\n", out_fd);
			}
			else
			{
				ft_putstr_fd(head->name, out_fd);
				ft_putstr_fd("\n", out_fd);
			}
		}
		head = head->next;
	}
}
