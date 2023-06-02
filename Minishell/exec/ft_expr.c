/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:50 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:23 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_math_instructions(t_cmd2 *cmds, char oper)
{
	int	result;
	
	result = 0;
	if (cmds->comd->next->next->next)
	{
		if (oper == '+')
			result = ft_atoi(cmds->comd->next->data)
				+ ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '-')
			result = ft_atoi(cmds->comd->next->data)
				- ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '*')
			result = ft_atoi(cmds->comd->next->data)
				* ft_atoi(cmds->comd->next->next->next->data);
		else if (oper == '/')
			result = ft_atoi(cmds->comd->next->data)
				/ ft_atoi(cmds->comd->next->next->next->data);
		cmds->comd->next->data = ft_strdup(ft_itoa(result));
		ft_delete_first_n(&cmds->comd->next->next);
		ft_delete_first_n(&cmds->comd->next->next);
	}
}

void	ft_math_helper(t_cmd2 *cmds)
{
	if (cmds->comd->next->next->data[0] == '+')
		ft_math_instructions(cmds, '+');
	else if (cmds->comd->next->next->data[0] == '-')
		ft_math_instructions(cmds, '-');
	else if (cmds->comd->next->next->data[0] == '*')
		ft_math_instructions(cmds, '*');
	else if (cmds->comd->next->next->data[0] == '/')
		ft_math_instructions(cmds, '/');
}

void	ft_expr(t_cmd2 *cmds)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strcmp(cmds->comd->data, "expr") == 0)
	{
		if (cmds->comd->next)
		{
			if (ft_strcmp(cmds->comd->next->data, "$?") == 0)
			{
				tmp = ft_itoa(g_vars->exit_status);
				cmds->comd->next->data = ft_strdup(tmp);
			}
			if (cmds->comd->next->next->next
				&& ft_strcmp(cmds->comd->next->next->next->data, "$?") == 0)
			{
				tmp = ft_itoa(g_vars->exit_status);
				cmds->comd->next->next->next->data = ft_strdup(tmp);
			}
		}
		if (cmds->comd->next->next)
			ft_math_helper(cmds);
	}
}
