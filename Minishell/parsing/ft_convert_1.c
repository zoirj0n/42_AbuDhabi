/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:38 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:39 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	ft_quote3(t_token **tok, t_token **tmp)
{
	char	*str_tmp2;

	str_tmp2 = NULL;
	if ((*tmp))
		str_tmp2 = (*tmp)->data;
	if ((*tok) && (*tok)->next
		&& ((*tok)->next->type == S_QUOTE
			|| (*tok)->next->type == D_QUOTE))
		ft_quote3_1(tok, tmp, &str_tmp2);
	else
	{
		ft_convert_dollar(tok, tmp);
		ft_double_free(tok, &str_tmp2);
	}
	if ((*tok))
		(*tok) = (*tok)->next;
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_add_1(t_token **tok, t_token **new, t_token **tmp)
{
	if (((*tmp) && ((((*tok) && (*tok)->type == W_SPACE))
				|| ((*tmp) && !(*tok))
				|| ((*tok) && ((*tok)->type == PIPE
						|| (*tok)->type == LESS
						|| (*tok)->type == D_LESS
						|| (*tok)->type == GREAT
						|| (*tok)->type == D_GREAT)))))
	{
		addback_token(new,
			(*tmp)->type,
			ft_token_len(*new) + 1,
			(*tmp)->data);
		if ((*tmp))
			ft_destroy_tokens(&(*tmp));
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_add_2(t_token **tok, t_token **new)
{
	if ((*tok)
		&& (((*tok)->type == LESS)
			|| ((*tok)->type == D_LESS)
			|| ((*tok)->type == GREAT)
			|| ((*tok)->type == D_GREAT)
			|| ((*tok)->type == PIPE)))
	{
		addback_token(new,
			(*tok)->type,
			ft_token_len(*new) + 1,
			(*tok)->data);
		(*tok) = (*tok)->next;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_quote_4(t_token **token, t_token **tmp_tok, char **str_tmp)
{
	if ((*tmp_tok))
	{
		(*str_tmp) = ft_strdup((*tmp_tok)->data);
		free((*tmp_tok)->data);
		(*tmp_tok)->data = ft_strjoin((*str_tmp), (*token)->data);
		free((*str_tmp));
		(*str_tmp) = NULL;
	}
	else
		(*tmp_tok) = create_tok((*token)->type, 0, (*token)->data);
	(*token) = (*token)->next;
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_convert(t_token **token, t_token **new_token)
{
	t_token	*tmp_tok;
	char	*str_tmp;
	char	*str_tmp2;

	tmp_tok = NULL;
	str_tmp = NULL;
	str_tmp2 = NULL;
	while ((*token))
	{
		ft_quote_care(token, new_token, &tmp_tok, &str_tmp);
		if ((*token) && (*token)->type == DOLLAR)
			quote_core(token, &tmp_tok, &str_tmp2);
		if ((*token) && (*token)->type == WORD)
			ft_quote_4(token, &tmp_tok, &str_tmp);
		ft_add_1(token, new_token, &tmp_tok);
		ft_add_2(token, new_token);
	}
}
/*----------------------------------------------*/
