/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forked_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:54 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:26 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin_cmds(t_cmd2 *cmd)
{
	char	*clone;
	
	clone = NULL;
	if (cmd && cmd->comd)
	{
		clone = ft_strdup(cmd->comd->data);
		if (cmd->comd && (ft_strcmp(ft_str_lower(clone), "echo") == 0
				|| ft_strcmp(ft_str_lower(clone), "env") == 0
				|| ft_strcmp(cmd->comd->data, "unset") == 0
				|| ft_strcmp(cmd->comd->data, "export") == 0
				|| ft_strcmp(cmd->comd->data, "cd") == 0
				|| ft_strcmp(ft_str_lower(clone), "pwd") == 0
				|| ft_strcmp(cmd->comd->data, "exit") == 0))
		{
			free(clone);
			return (1);
		}
		free(clone);
	}
	return (0);
}

static	void	helper_forked_blt_cont(t_cmd2 *cmd, t_env *copy_env, int fd_out)
{
	if (ft_strcmp(ft_str_lower(cmd->comd->data), "pwd") == 0)
		ft_pwd(fd_out);
	else if (ft_strcmp(cmd->comd->data, "exit") == 0)
	{
		if (cmd->comd->next)
		{
			ft_close_outfile(cmd->output);
			ft_close_infile(cmd->input);
			ft_free_copy_env(copy_env);
			exit ((char)(ft_atoi(cmd->comd->next->data)));
		}
		ft_close_outfile(cmd->output);
		ft_close_infile(cmd->input);
		exit(20);
	}
}

static void	helper_forked_builtin(t_cmd2 *cmd, t_env *copy_env, int fd_out)
{
	if (ft_strcmp(ft_str_lower(cmd->comd->data), "echo") == 0)
		ft_echo(cmd->comd, fd_out);
	else if (ft_strcmp(cmd->comd->data, "unset") == 0)
		ft_unset(&copy_env, cmd->comd);
	else if (ft_strcmp(cmd->comd->data, "export") == 0)
		ft_export(&copy_env, cmd->comd, fd_out);
	else if (ft_strcmp(cmd->comd->data, "cd") == 0)
		ft_cd(&copy_env, cmd->comd);
	else if (ft_strcmp(ft_str_lower(cmd->comd->data), "env") == 0)
	{
		if (!cmd->comd->next)
			ft_env(copy_env, 0, fd_out);
	}
	helper_forked_blt_cont(cmd, copy_env, fd_out);
}

void	ft_child_process_builtin(t_cmd2 *cmd)
{
	close(g_vars->fd_in);
	close(g_vars->fd_out);
	ft_close_outfile(cmd->output);
	ft_close_infile(cmd->input);
	g_vars->flag = 0;
	ft_free_vars();
	exit (0);
}

void	ft_forked_builtin(t_cmd2 *cmd, t_env *copy_env, int nb_cmd)
{
	int	pid;
	int	fd_out;
	int	fd_in;

	g_vars->flag = 1;
	fd_in = ft_open_infile(cmd->input);
	fd_out = ft_open_outfile(cmd->output);
	unlink("heredoc.txt");
	pid = fork();
	if (pid < 0)
		strerror(errno);
	else if (pid == 0)
	{
		if ((fd_in < 0) | (fd_out < 0))
		{
			g_vars->exit_status = 1;
			exit (1);
		}
		ft_dup2(cmd, fd_in, fd_out);
		ft_close_pipes(cmd, nb_cmd);
		helper_forked_builtin(cmd, copy_env, fd_out);
		ft_child_process_builtin(cmd);
	}
	else
		g_vars->flag = 0;
}
