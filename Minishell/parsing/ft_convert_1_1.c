/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:36 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:37 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_quote_care(t_token **token, t_token **new_token,
			t_token **tmp_tok, char **str_tmp)
{
	while ((*token) && (*token)->type == W_SPACE)
		(*token) = (*token)->next;
	if ((*token) && ((*token)->type == S_QUOTE
			|| (*token)->type == D_QUOTE))
	{
		ft_quote2(token, new_token, tmp_tok, str_tmp);
	}
}

void	quote_core(t_token **token, t_token **tmp_tok, char **str_tmp2)
{
	if ((*tmp_tok))
		(*str_tmp2) = (*tmp_tok)->data;
	if ((*token) && (*token)->next
		&& ((*token)->next->type == S_QUOTE
			|| (*token)->next->type == D_QUOTE))
	{
		ft_quote3_1(token, tmp_tok, str_tmp2);
	}
	else
	{
		ft_convert_dollar(token, tmp_tok);
		if ((*str_tmp2))
			free((*str_tmp2));
	}
}
