/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:29 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:36 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_plus_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '+')
	{
		str[i - 1] = '\0';
		return (1);
	}
	return (0);
}

int	ft_mini_error_handling(char *command, int flag_plus_equal)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i + 1] == '\0' && command[i] == '+' && flag_plus_equal)
			return (0);
		if ((ft_isdigit(command[0])
				|| ft_isalnum(command[i]) == 0) && (command[0] != '_'))
		{
			ft_putstr_fd("export:`", 2);
			ft_putstr_fd(command, 2);
			ft_putstr_fd("\': not a valid identifier\n", 2);
			g_vars->exit_status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_plus(char *str_n, char *str_v, t_env **head, t_env **newnode)
{
	t_env	*temp;

	temp = NULL;
	if (ft_check_plus_sign(str_n))
	{
		temp = ft_search_list(head, str_n);
		if (temp)
		{
			temp->value = ft_strjoin(temp->value, str_v);
			*newnode = ft_create_node(temp->name, temp->value);
			ft_delete_from_list(head, str_n);
		}
		else
			*newnode = ft_create_node(str_n, str_v);
	}
}

int	ft_error_getting_value(t_comd **command)
{
	char	*tmp;

	tmp = ft_get_value((*command)->data);
	if (tmp && ft_strcmp(tmp, "Error") == 0)
	{
		ft_mini_error_handling((*command)->data, 0);
		(*command) = (*command)->next;
		free(tmp);
		return (1);
	}
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_checking_proper_str_name(char *str_name, t_comd **command)
{
	if (ft_mini_error_handling(str_name, 1))
	{
		*command = (*command)->next;
		return (1);
	}
	return (0);
}
