/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:32 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:33 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*---------------------------------------------------*/
int	nb_pipes(t_token *token)
{
	int		p;
	t_token	*tmp;

	tmp = token;
	p = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			p++;
		tmp = tmp->next;
	}
	return (p);
}
/*---------------------------------------------------*/

/*---------------------------------------------------*/
void	inside_quote(t_token **token)
{
	int	type;

	type = (*token)->type;
	(*token) = (*token)->next;
	while ((*token) && (*token)->type != type)
		(*token) = (*token)->next;
	(*token) = (*token)->next;
}

int	valid_pipe_type(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->type == W_SPACE)
		tmp = tmp->next;
	if (tmp && tmp->type == PIPE)
		return (0);
	while (tmp)
	{
		if (tmp && (tmp->type == S_QUOTE || tmp->type == D_QUOTE))
			inside_quote(&tmp);
		else if (tmp && tmp->type == PIPE)
		{
			tmp = tmp->next;
			while (tmp && tmp->type == W_SPACE)
				tmp = tmp->next;
			if (tmp && tmp->type == PIPE)
				return (0);
			if (!tmp)
				return (0);
		}
		else
			tmp = tmp->next;
	}
	return (1);
}

/*---------------------------------------------------*/
// int	valid_pipe_type(t_token *token)
// {
// 	t_token	*tmp;

// 	tmp = token;
// 	while (tmp && tmp->type == W_SPACE)
// 		tmp = tmp->next;
// 	if (tmp && tmp->type == PIPE)
// 		return (0);
// 	while (tmp)
// 	{
// 		if (tmp && tmp->type == PIPE)
// 		{
// 			tmp = tmp->next;
// 			while (tmp && tmp->type == W_SPACE)
// 				tmp = tmp->next;
// 			if (tmp && tmp->type == PIPE)
// 				return (0);
// 			if (!tmp)
// 				return (0);
// 		}
// 		else if (tmp)
// 			tmp = tmp->next;
// 	}
// 	return (1);
// }
/*---------------------------------------------------*/
