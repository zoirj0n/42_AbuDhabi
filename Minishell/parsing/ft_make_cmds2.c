/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cmds2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:28 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:29 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
t_cmd2	*ft_make_cmd2(t_token *token)
{
	t_cmd2	*cmd;

	cmd = NULL;
	while (token)
	{
		if (token && token->type != PIPE)
		{
			if (!cmd)
				cmd = create_cmd2(&token);
			else
				add_back_cmd2(&cmd, &token);
		}
		if (token && token->type == PIPE)
			token = token->next;
	}
	return (cmd);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_cmds2	*ft_make_cmds2(t_token *token)
{
	t_cmds2	*cmds;

	cmds = NULL;
	cmds = (t_cmds2 *)malloc(sizeof(t_cmds2));
	cmds->nb_cmd = nb_pipes(token) + 1;
	cmds->cmd = ft_make_cmd2(token);
	return (cmds);
}
/*----------------------------------------------*/
