/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:45 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:46 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------------------------------------*/
t_token	*create_tok(int type, int pos, char *data)
{
	t_token	*new_token;

	new_token = NULL;
	if (!data)
		return (NULL);
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->pos = pos;
	new_token->data = ft_strdup(data);
	new_token->next = NULL;
	new_token->prev = NULL;
	if (!new_token->data)
	{
		free(new_token);
		return (NULL);
	}
	return (new_token);
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
void	last_token(t_token **token)
{
	t_token	*tmp;

	tmp = NULL;
	if (!*token)
		return ;
	tmp = *token;
	while (tmp->next)
		tmp = tmp->next;
	(*token) = tmp;
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
void	addback_token(t_token **token, int type, int pos, char *data)
{
	t_token	*first;
	t_token	*tmp;

	first = NULL;
	tmp = NULL;
	if (!*token)
		(*token) = create_tok(type, pos, data);
	else
	{
		first = *token;
		last_token(token);
		tmp = create_tok(type, pos, data);
		if (!tmp)
		{
			(*token) = first;
			return ;
		}
		(*token)->next = tmp;
		tmp->prev = (*token);
		(*token) = first;
	}
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
void	change_pointer(t_token **token, t_token **new)
{
	(*token) = (t_token *)malloc(sizeof(t_token));
	(*token)->type = (*new)->type;
	(*token)->pos = (*new)->pos;
	(*token)->data = (*new)->data;
	(*token)->next = (*new)->next;
}
/*-----------------------------------------------------------------*/

/*-----------------------------------------------------------------*/
int	ft_token_len(t_token *token)
{
	t_token	*tmp;
	int		len;

	len = 0;
	tmp = token;
	if (!tmp)
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
/*-----------------------------------------------------------------*/
