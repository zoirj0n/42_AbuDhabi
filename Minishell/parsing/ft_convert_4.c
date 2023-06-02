/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:55 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:56 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	ft_handle_quote1(t_token **token, t_token **tmp, int pos)
{
	int	type;

	if ((*token))
		type = (*token)->type;
	if ((*token) && (*token)->next && ((*token)->next->type == type))
	{
		(*token) = (*token)->next;
		if (empty_but_space(*token))
		{
			*tmp = create_tok(W_SPACE, pos, "");
			(*token) = (*token)->next;
		}
	}
	else if ((*token) && (*token)->type != W_SPACE)
		ft_convert_quote(token, tmp);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_convert_dollar(t_token **token, t_token **tmp)
{
	char	*str;

	str = NULL;
	if ((*token) && (*token)->type == DOLLAR)
	{
		ft_dollar_str(token, &str);
		if ((*token) && (*token)->next)
			(*token) = (*token)->next;
	}
	if (!(*tmp))
	{
		(*tmp) = create_tok(WORD, 0, str);
		if (str)
			free(str);
	}
	else if ((*tmp) && (*tmp)->data && str)
	{
		(*tmp)->data = ft_strjoin((*tmp)->data, str);
		free(str);
	}
}
/*-----------------------------------------------*/

/*----------------------------------------------*/
void	join_all_part(t_token **tmp, char **str, char **str_tmp)
{
	if (!(*str))
	{
		if (is_new_line((*tmp)->data)
			&& valid_pos_nline(*tmp)
			&& (((*tmp)->next->type == S_QUOTE)
				|| ((*tmp)->next->type == D_QUOTE)))
			(*str) = ft_make_new_line(tmp);
		else
			(*str) = (*tmp)->data;
	}
	else
	{
		if ((*tmp)->next)
		{
			(*str_tmp) = (*str);
			(*str) = ft_strjoin((*str_tmp), (*tmp)->data);
		}
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_double_free(t_token **tmp, char **str_tmp)
{
	t_token	*dummy_token;
	int		i;

	i = 0;
	dummy_token = *tmp;
	while (dummy_token && dummy_token->prev)
		dummy_token = dummy_token->prev;
	while (dummy_token)
	{
		if (dummy_token->data == *str_tmp)
			i = 1;
		dummy_token = dummy_token->next;
	}
	if (i == 0)
	{
		free((*str_tmp));
		(*str_tmp) = NULL;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	join_all_str(t_token **tmp, char **str, int type)
{
	char	*str_tmp;

	str_tmp = NULL;
	while ((*tmp) && ((*tmp)->type != type))
	{
		if (type == D_QUOTE && (*tmp)->type == DOLLAR)
			ft_dollar_str(tmp, str);
		else
			join_all_part(tmp, str, &str_tmp);
		ft_double_free(tmp, &str_tmp);
		if (*tmp)
			(*tmp) = (*tmp)->next;
	}
}
/*----------------------------------------------*/