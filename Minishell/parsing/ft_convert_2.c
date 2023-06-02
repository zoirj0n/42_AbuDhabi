/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:48 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:49 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
int	empty_but_space(t_token *token)
{
	t_token	*tmp;
	t_token	*tmp1;
	int		count;

	count = 0;
	tmp = token;
	tmp1 = token;
	tmp = tmp->next;
	tmp1 = tmp1->next;
	while (tmp1)
	{
		if (tmp1->type == W_SPACE)
			count++;
		else
		{
			count = 0;
			break ;
		}
		tmp1 = tmp1->next;
	}
	if (tmp && !count && tmp->type == W_SPACE)
		return (1);
	return (0);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_quote1(t_token **tok, t_token **tmp_tok, char **str_tmp)
{
	char	*str_tmp3;
	t_token	*dummy_token;
	int		i;

	i = 0;
	dummy_token = *tok;
	str_tmp3 = (*tmp_tok)->data;
	(*tmp_tok)->data = ft_strjoin(*str_tmp, (*tmp_tok)->data);
	free(str_tmp3);
	while (dummy_token && dummy_token->prev)
		dummy_token = dummy_token->prev;
	while (dummy_token)
	{
		if ((dummy_token->data) == *str_tmp)
			i = 1;
		dummy_token = dummy_token->next;
	}
	if (i == 0)
	{
		free(*str_tmp);
		*str_tmp = NULL;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_quote2(t_token **tok, t_token **new, t_token **tmp, char **str)
{
	if ((*tmp))
	{
		(*str) = ft_strdup((*tmp)->data);
		ft_destroy_tokens(tmp);
	}
	ft_handle_quote1(tok, tmp, 0);
	if ((*str) && (*tmp))
	{
		ft_quote1(tok, tmp, str);
	}
	else if ((*str))
	{
		(*tmp) = create_tok(WORD, 0, (*str));
		free((*str));
	}
	if ((*tok) && (*tmp) && (*tok)->type == W_SPACE)
	{
		addback_token(new,
			(*tmp)->type,
			ft_token_len(*new) + 1,
			(*tmp)->data);
		ft_destroy_tokens(&(*tmp));
	}
	if ((*tok))
		(*tok) = (*tok)->next;
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_quote3_1(t_token **tok, t_token **tmp, char **str)
{
	int		type;
	char	*str_tmp3;
	t_token	*tmp_tok2;

	type = 0;
	str_tmp3 = NULL;
	tmp_tok2 = NULL;
	(*tok) = (*tok)->next;
	type = (*tok)->type;
	if ((*tok)->next && (*tok)->next->type == type)
		(*tok) = (*tok)->next;
	else
		ft_handle_quote1(tok, &tmp_tok2, 0);
	if ((*str) && tmp_tok2)
	{
		str_tmp3 = (*tmp)->data;
		(*tmp)->data = ft_strjoin((*str), tmp_tok2->data);
		free(str_tmp3);
	}
	ft_destroy_tokens(&tmp_tok2);
}
/*----------------------------------------------*/