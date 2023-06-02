/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:15 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:28:52 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*g_vars;

void	sig_handler(int signum)
{
	(void)signum;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_vars->exit_status = 1;
	}
	if (g_vars->flag == 1)
	{
		unlink("heredoc.txt");
		ft_putstr_fd("\33[2K\r", 1);
		g_vars->exit_status = 1;
		ft_free_vars();
		exit (1);
	}
}

void	ft_init_glob(t_env *copy_env)
{
	g_vars = (t_vars *)malloc(sizeof(t_vars));
	g_vars->env_clone = NULL;
	g_vars->copy_env = NULL;
	g_vars->exit_status = 0;
	g_vars->fd_in = dup(0);
	g_vars->fd_out = dup(1);
	g_vars->flag = 0;
	g_vars->copy_env = copy_env;
}

void	ft_main_function(char *command, char **env, t_env *copy_env)
{
	int		err;
	t_token	*real_token;
	t_cmds2	*cmds;

	cmds = NULL;
	real_token = NULL;
	err = 0;
	add_history(command);
	g_vars->env_clone = make_clone_env(copy_env);
	real_token = ft_parser(command, env, &err);
	if (!err)
	{
		cmds = ft_make_cmds2(real_token);
		g_vars->cmds = cmds;
		ft_destroy_tokens(&real_token);
		ft_multiple_pipes(cmds->cmd, copy_env, cmds->nb_cmd);
		ft_free_vars2();
	}
	else
		err = 0;
}

void	ft_ctr_d(t_env *copy_env)
{
	ft_free_copy_env(copy_env);
	free(g_vars);
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	char	*command;
	t_env	*copy_env;
	t_token	*real_token;
	int		err;
	t_cmds2	*cmds;

	cmds = NULL;
	err = 0;
	copy_env = NULL;
	real_token = NULL;
	(void)av;
	(void)ac;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_copy_env(&copy_env, env);
	ft_init_glob(copy_env);
	while (1)
	{
		command = readline("minishell$> ");
		if (!command)
			ft_ctr_d(copy_env);
		if (command[0] != 0)
			ft_main_function(command, env, copy_env);
	}
}
