/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:09 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:11 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_copy_env(t_env *copy_env)
{
	t_env	*tmp;

	tmp = NULL;
	while (copy_env)
	{
		tmp = copy_env;
		if (copy_env->name)
			free(copy_env->name);
		if (copy_env->value)
			free(copy_env->value);
		copy_env = copy_env->next;
		free(tmp);
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*--------------------------------------------*/
void	ft_free_vars(void)
{
	if (g_vars && g_vars->env_clone)
		ft_free_array(g_vars->env_clone);
	if (g_vars && g_vars->copy_env)
		ft_free_copy_env(g_vars->copy_env);
	if (g_vars && g_vars->cmds)
		ft_destroy_cmds2(&(g_vars->cmds));
	if (g_vars)
		free(g_vars);
}

void	ft_free_vars2(void)
{
	if (g_vars && g_vars->env_clone)
		ft_free_array(g_vars->env_clone);
	if (g_vars && g_vars->cmds)
		ft_destroy_cmds2(&(g_vars->cmds));
}

void	ft_delete_first_n(t_comd **head)
{
	t_comd	*tmp;

	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
/*--------------------------------------------*/