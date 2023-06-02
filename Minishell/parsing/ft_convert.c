/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:59 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:00 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	ft_dollar_str(t_token **token, char **str)
{
	char	*new_str;
	char	*tmp;
	int		i;

	new_str = NULL;
	i = 0;
	new_str = ft_dollar_helper(token);
	if (*str && new_str)
	{
		tmp = ft_strjoin(*str, new_str);
		i = ft_dummpy_token_check(*token, str);
		if (i == 0)
		{
			free(*str);
			*str = NULL;
		}
		free(new_str);
		*str = tmp;
	}
	else if (new_str)
		*str = new_str;
	(*token) = (*token)->next;
}
/*----------------------------------------------*/

/*----------------------------------------------*/
char	*ft_conv(t_token **token, char **new_str)
{
	int		new_type;
	char	*str_tmp1;
	char	*str_tmp4;

	new_type = 0;
	(*token) = (*token)->next;
	new_type = (*token)->type;
	if ((*token)->next && (*token)->next->type == new_type)
	{
		str_tmp1 = ft_strdup("");
		(*token) = (*token)->next;
	}
	else
		str_tmp1 = str_quoted(token, new_type);
	if (str_tmp1)
		str_tmp4 = ft_strjoin((*new_str), str_tmp1);
	else
		str_tmp4 = ft_strdup((*new_str));
	ft_double_free(token, &str_tmp1);
	if ((*new_str))
	{
		free((*new_str));
		(*new_str) = NULL;
	}
	return (str_tmp4);
}

void	quote_loop(t_token **token, char **new_str, char **str_tmp3)
{
	while (*token && (*token)->type != W_SPACE
		&& (*token)->next && ((*token)->next->type == S_QUOTE
			|| (*token)->next->type == D_QUOTE))
			(*new_str) = ft_conv(token, new_str);
	while ((*token) && (*token)->next && ((*token)->next->type == WORD))
	{
		*str_tmp3 = ft_strjoin((*new_str), (*token)->next->data);
		(*token) = (*token)->next;
	}
}

void	quote_add_free(t_token **tmp, char **str_tmp3, char **new_str)
{
	if (*str_tmp3)
	{
		(*tmp) = create_tok(WORD, 0, *str_tmp3);
		free(*str_tmp3);
	}
	else if (*new_str)
	{
		(*tmp) = create_tok(WORD, 0, *new_str);
		free(*new_str);
		*new_str = NULL;
	}
}
/*----------------------------------------------*/

void	ft_convert_quote(t_token **token, t_token **tmp)
{
	char	*new_str;
	int		type;
	char	*str_tmp2;
	char	*str_tmp3;

	str_tmp2 = NULL;
	str_tmp3 = NULL;
	new_str = NULL;
	type = 0;
	if (*token)
		type = (*token)->type;
	str_tmp2 = str_quoted(token, type);
	new_str = ft_strdup(str_tmp2);
	ft_double_free(token, &str_tmp2);
	quote_loop(token, &new_str, &str_tmp3);
	quote_add_free(tmp, &str_tmp3, &new_str);
	while ((*token) && (*token)->next && ((*token)->next->type == W_SPACE))
		(*token) = (*token)->next;
	if (new_str)
		free(new_str);
}
