/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:32 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:33 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------------*/
void	to_last_cmd2(t_cmd2 **cmd)
{
	while ((*cmd) && (*cmd)->next)
		(*cmd) = (*cmd)->next;
}
/*------------------------------------------*/

/*------------------------------------------*/
t_cmd2	*create_cmd2(t_token **token)
{
	t_cmd2	*cmd;

	cmd = NULL;
	cmd = (t_cmd2 *)malloc(sizeof(t_cmd2));
	if (!cmd)
		return (NULL);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->comd = ft_make_comd(token);
	cmd->input = ft_make_input(token);
	cmd->output = ft_make_output(token);
	return (cmd);
}
/*-------------------------------------------*/

/*-------------------------------------------*/
void	add_back_cmd2(t_cmd2 **cmd, t_token **token)
{
	t_cmd2	*tmp;
	t_cmd2	*new;

	tmp = *cmd;
	to_last_cmd2(cmd);
	new = create_cmd2(token);
	(*cmd)->next = new;
	new->prev = (*cmd);
	*cmd = tmp;
}
/*----------------------------------------------*/
