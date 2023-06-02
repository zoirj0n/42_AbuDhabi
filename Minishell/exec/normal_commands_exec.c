/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_commands_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:06 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:40 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute(t_cmd2 *commands, t_env *copy_env)
{
	char	*get_real_path;
	char	**env;
	int		stat;
	char	**argv;

	if (commands->comd)
	{
		get_real_path = ft_get_path(commands->comd->data, copy_env);
		env = ft_get_2darray2(copy_env);
		if (ft_strcmp(commands->comd->data, "expr") == 0)
			ft_expr(commands);
		argv = ft_get_2darray1(commands->comd);
		stat = execve(get_real_path, argv, env);
		close(g_vars->fd_in);
		close(g_vars->fd_out);
		free(get_real_path);
		ft_free_array(argv);
		ft_free_array(env);
		(strerror(errno));
		exit(stat);
	}
}

void	create_child(t_cmd2 *commands, int nb_cmd, int fd_in, int fd_out)
{
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error creating with forks\n", 2);
		ft_free_vars();
		exit (11);
	}
	if (pid == 0)
	{
		ft_dup2(commands, fd_in, fd_out);
		ft_close_pipes(commands, nb_cmd);
		ft_execute(commands, g_vars->copy_env);
	}
	else if (pid != 0)
		g_vars->flag = 0;
}

void	ft_cmd_exec(t_cmd2 *commands, int nb_cmd)
{
	int		fd_in;
	int		fd_out;

	g_vars->flag = 1;
	fd_in = ft_open_infile(commands->input);
	if (fd_in < 0)
	{
		g_vars->exit_status = 1;
		return ;
	}
	unlink("heredoc.txt");
	fd_out = ft_open_outfile(commands->output);
	if (fd_out < 0)
	{
		g_vars->exit_status = 1;
		return ;
	}
	create_child(commands, nb_cmd, fd_in, fd_out);
}
