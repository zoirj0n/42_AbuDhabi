/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:25 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:26 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
t_cmd	*ft_make_cmd(t_token *token)
{
	t_cmd	*cmd;

	cmd = NULL;
	while (token)
	{
		if (token && token->type != PIPE)
		{
			if (!cmd)
				cmd = create_cmd(&token);
			else
				add_back_cmd(&cmd, &token);
		}
		if (token && token->type == PIPE)
			token = token->next;
	}
	return (cmd);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_cmds	*ft_make_cmds(t_token *token)
{
	t_cmds	*cmds;

	cmds = NULL;
	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	cmds->nb_cmd = nb_pipes(token) + 1;
	cmds->cmd = ft_make_cmd(token);
	return (cmds);
}
/*----------------------------------------------*/
