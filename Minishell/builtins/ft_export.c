/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:31 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:40 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *str)
{
	if (*str == '=')
		return (ft_strdup("Error"));
	while (*str)
	{
		if (*str == '=')
			return (ft_strdup(++str));
		str++;
	}
	return (NULL);
}

char	*ft_get_name(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '=')
		{
			*str = '\0';
			break ;
		}
		count++;
		str++;
	}
	return (str - count);
}

void	ft_create_nod(char *str_n, char *str_v, t_env **head, t_env **newnode)
{
	if (str_n && !str_v)
	{
		if (!ft_search_list(head, str_n))
			*newnode = ft_create_node(str_n, NULL);
	}
	else if (str_n && str_v)
	{
		if (ft_search_list(head, str_n))
			ft_delete_from_list(head, str_n);
		*newnode = ft_create_node(str_n, str_v);
	}
}

void	ft_helper_exp(t_env **head, t_env *newnode,
			char **str_name, char **str_value)
{
	ft_create_nod((*str_name), (*str_value), head, &newnode);
	ft_check_plus((*str_name), (*str_value), head, &newnode);
	ft_add_to_list(head, newnode);
	if ((*str_name))
		free((*str_name));
	if ((*str_value))
		free((*str_value));
}

void	ft_export(t_env **head, t_comd *command, int out_fd)
{
	char	*str_value;
	char	*str_name;
	t_env	*newnode;

	newnode = NULL;
	if (command->next == NULL)
		ft_env(*head, 1, out_fd);
	command = command->next;
	while (command)
	{
		if (ft_error_getting_value(&command))
			continue ;
		str_value = ft_get_value(command->data);
		str_name = ft_strdup(ft_get_name(command->data));
		if (ft_checking_proper_str_name(str_name, &command))
		{
			if (str_name)
				free(str_name);
			if (str_value)
				free(str_value);
			continue ;
		}
		ft_helper_exp(head, newnode, &str_name, &str_value);
		command = command->next;
	}
}
