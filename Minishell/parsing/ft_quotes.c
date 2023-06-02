/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:35 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:36 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------------------*/
int	check_last_token(t_token *token)
{
	t_token	*tmp;
	int		type;

	tmp = token;
	type = 0;
	while (tmp)
	{
		if (tmp->type == W_SPACE)
			tmp = tmp->next;
		if (tmp && tmp->type != W_SPACE)
		{
			type = tmp->type;
			tmp = tmp->next;
		}
	}
	if (type != WORD && type != S_QUOTE
		&& type != D_QUOTE && type != W_SPACE
		&& type != DOLLAR && type != N_LINE)
		return (0);
	return (1);
}
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
t_token	*check_last_quote(t_token *token, int type, int *count)
{
	t_token	*tmp;

	tmp = token->next;
	while (tmp)
	{
		if (tmp->type == type)
		{
			*count += 1;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
int	check_quotes(t_token *tokens)
{
	t_token	*tmp;
	int		type;
	int		count;

	count = 0;
	type = 0;
	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == S_QUOTE || tmp->type == D_QUOTE)
		{
			type = tmp->type;
			count++;
			tmp = check_last_quote(tmp, type, &count);
			if (!tmp || ((count % 2) != 0))
				return (0);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	if ((count != 0) && (count % 2) == 0)
		return (1);
	return (0);
}
/*----------------------------------------------------------*/
