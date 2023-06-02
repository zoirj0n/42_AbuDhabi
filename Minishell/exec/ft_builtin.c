/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:46 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:16 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isnum(char *str)
{

	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_helper_builtin(t_cmd2 *cmd, t_env *copy_env, int out_fd)
{
	if (ft_strcmp(ft_str_lower(cmd->comd->data), "env") == 0)
	{
		if (!cmd->comd->next)
			ft_env(copy_env, 0, out_fd);
	}
	else if (ft_strcmp(cmd->comd->data, "unset") == 0)
		ft_unset(&copy_env, cmd->comd->next);
	else if (ft_strcmp(cmd->comd->data, "export") == 0)
		ft_export(&copy_env, cmd->comd, out_fd);
	else if (ft_strcmp(cmd->comd->data, "cd") == 0)
		ft_cd(&copy_env, cmd->comd);
	else if (ft_strcmp(ft_str_lower(cmd->comd->data), "pwd") == 0)
		ft_pwd(out_fd);
}

void	ft_builtin(t_cmd2 *cmd, t_env *copy_env)
{
	int	out_fd;
	int	in_fd;

	in_fd = ft_open_infile(cmd->input);
	unlink("heredoc.txt");
	out_fd = ft_open_outfile(cmd->output);
	if ((in_fd == -1) | (out_fd == -1))
	{
		g_vars->exit_status = 1;
		return ;
	}
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		ft_putstr_fd("writing  file failed\n", 2);
	if (dup2(in_fd, STDIN_FILENO) < 0)
		ft_putstr_fd(strerror(errno), 2);
	if (ft_strcmp(ft_str_lower(cmd->comd->data), "echo") == 0)
		ft_echo(cmd->comd, out_fd);
	else if (ft_strcmp(cmd->comd->data, "exit") == 0)
		ft_exit(cmd, copy_env);
	ft_helper_builtin(cmd, copy_env, out_fd);
	ft_close_infile(cmd->input);
	ft_close_outfile(cmd->output);
}
