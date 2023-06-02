/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:31 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:32 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
char	**ft_tab_args(t_token **token)
{
	char	**tab;
	int		tab_size;
	int		i;

	i = 0;
	tab_size = tab_len(*token);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	while ((*token) && (*token)->type != PIPE)
	{
		tab[i] = ft_make_str((*token)->data);
		(*token) = (*token)->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_cmd	*create_cmd(t_token **token)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->args = ft_tab_args(token);
	return (cmd);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	add_back_cmd(t_cmd **cmd, t_token **token)
{
	t_cmd	*tmp;
	t_cmd	*new;

	tmp = *cmd;
	to_last_cmd(cmd);
	new = create_cmd(token);
	(*cmd)->next = new;
	new->prev = (*cmd);
	*cmd = tmp;
}
/*----------------------------------------------*/
