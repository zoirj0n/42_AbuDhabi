/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_real_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:56 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:29 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_full_path(char **full_path, char *str)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = NULL;
	s2 = NULL;
	while (full_path[i])
	{
		s1 = ft_strjoin(full_path[i], "/");
		s2 = ft_strjoin(s1, str);
		free(s1);
		if (access(s2, R_OK) == 0)
			return (s2);
		free(s2);
		i++;
	}
	return (NULL);
}

char	*ft_error_path(char *str, char *str_res)
{
	if (str_res != NULL)
	{
		write(2, str, ft_strlen(str));
		write(2, ": Permission denied\n", 20);
		close(g_vars->fd_in);
		close(g_vars->fd_out);
		free(str_res);
		ft_free_vars();
		exit (126);
	}
	else
	{
		write(2, str, ft_strlen(str));
		write(2, ": command not found\n", 20);
		close(g_vars->fd_in);
		close(g_vars->fd_out);
		free(str_res);
		ft_free_vars();
		exit (127);
	}
	return (NULL);
}

char	*real_path(char *str, char *str_res)
{
	if (ft_strcmp(str, str_res) == 0)
	{
		if (access(str_res, X_OK) == 0)
			return (str_res);
	}
	else
	{
		if (str_res && access(str_res, X_OK) == 0)
			return (str_res);
		else if (access(str, X_OK) == 0)
			return (str);
	}
	return (NULL);
}

char	*ft_get_path(char *str, t_env *copy_env)
{
	char	**full_path;
	char	*str_res;
	char	*result;

	str_res = NULL;
	while (copy_env)
	{
		if (ft_strcmp(copy_env->name, "PATH") == 0)
		{
			full_path = ft_split(copy_env->value, ':');
		}
		copy_env = copy_env->next;
	}
	str_res = ft_full_path(full_path, str);
	ft_free_array(full_path);
	result = real_path(str, str_res);
	if (result)
		return (result);
	return (ft_error_path(str, str_res));
}
