/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:21 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:25 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_print(t_comd *real_token, int out_fd)
{
	if (real_token->next)
	{
		if (ft_strcmp(real_token->data, "$?") == 0)
			ft_putstr_fd(ft_itoa(g_vars->exit_status), out_fd);
		else
			ft_putstr_fd(real_token->data, out_fd);
		ft_putstr_fd(" ", out_fd);
	}
	else
	{
		if (ft_strcmp(real_token->data, "$?") == 0)
			ft_putstr_fd(ft_itoa(g_vars->exit_status), out_fd);
		else
			ft_putstr_fd(real_token->data, out_fd);
	}
}

int	check_quest_mark(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_exit_stat_str(char *str, int out_fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
		{
			tmp = ft_itoa(g_vars->exit_status);
			ft_putstr_fd(tmp, out_fd);
			free(tmp);
			i++;
		}
		else
			ft_putchar_fd(str[i], out_fd);
		i++;
	}
}

void	ft_echo(t_comd *real_token, int out_fd)
{
	int	flag;
	int	count;

	real_token = real_token->next;
	flag = 0;
	count = 0;
	while (real_token)
	{
		if (ft_strcmp(real_token->data, "-n") == 0 && flag == 0 && count == 0)
			flag = 1;
		else if (check_quest_mark(real_token->data))
			ft_print_exit_stat_str(real_token->data, out_fd);
		else
			echo_print(real_token, out_fd);
		real_token = real_token->next;
		count++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", out_fd);
}
