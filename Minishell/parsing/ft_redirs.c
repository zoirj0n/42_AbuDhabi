/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:43 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:44 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
int	is_redir(int type)
{
	if (type == GREAT || type == D_GREAT || type == LESS
		|| type == D_LESS)
		return (type);
	return (0);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	valid_redir(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp && (tmp->type == GREAT || tmp->type == D_GREAT
				|| tmp->type == LESS || tmp->type == D_LESS))
		{
			tmp = tmp->next;
			while (tmp && tmp->type == W_SPACE)
				tmp = tmp->next;
			if ((tmp && tmp->type != WORD) || !tmp)
				return (1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
/*----------------------------------------------*/
