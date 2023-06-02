/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:04 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:28:57 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_copy_env(t_env **head, char **env)
{
	t_env	*newnode;
	char	**var;
	int		i;
	
	newnode = NULL;
	i = 0;
	while (env[i])
	{
		var = ft_split(env[i], '=');
		if (var[0] && var[1])
			newnode = ft_create_node(var[0], var[1]);
		else
			newnode = ft_create_node(var[0], "");
		if (!head)
			head = &newnode;
		else
			ft_add_to_list(head, newnode);
		ft_free_array(var);
		i++;
	}
	newnode = ft_create_node("OLDPWD", NULL);
	ft_add_to_list(head, newnode);
}

void	print_env(t_env *copy_env)
{
	while (copy_env)
	{
		printf("%s=%s\n", copy_env->name, copy_env->value);
		copy_env = copy_env->next;
	}
}
