/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:02 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:32:03 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------*/
void	ft_expand0(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (!(*str))
		(*str) = strdup("$");
	else
	{
		tmp = *str;
		*str = ft_strjoin(tmp, "$");
		free(tmp);
		tmp = NULL;
	}
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_join_part1(t_token **token, char **str)
{
	if (!*token)
		ft_expand0(str);
	else if ((*token) && is_another_symb((*token)->data))
	{
		if ((*str))
			ft_expand1(token, str);
		else
			ft_expand2(token, str);
		if ((*token) && (*token)->type == DOLLAR)
			ft_join_tok2(token, str);
	}
	else if ((*token) && is_another_digit((*token)->data))
	{
		ft_expand3(token, str);
		if ((*token) && (*token)->type == DOLLAR)
			ft_join_tok2(token, str);
	}
	else
	{
		ft_expand4(token, str);
		if ((*token) && (*token)->type == DOLLAR)
			ft_join_tok2(token, str);
	}
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_join_tok2(t_token **token, char **str)
{
	if ((*token) && (*token)->type == DOLLAR)
	{
		(*token) = (*token)->next;
		ft_join_part1(token, str);
	}
	else
		ft_join_part2(token, str);
}
/*-----------------------------------*/

/*-----------------------------------*/
t_token	*ft_word(t_token **token)
{
	t_token	*new;
	t_token	*tmp;

	tmp = *token;
	new = NULL;
	ft_join_word2(&tmp, &new);
	return (new);
}
/*-----------------------------------*/
