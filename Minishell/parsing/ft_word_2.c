/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:54 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:55 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------*/
int	is_another_symb(char *str)
{
	char	*symbols;
	int		i;
	int		j;

	i = 0;
	j = 0;
	symbols = "! ~`\"()@#\\%£&*-'+={}[];:,.?/$";
	while (symbols[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == symbols[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
/*-----------------------------------*/

/*-----------------------------------*/
int	is_another_digit(char *str)
{
	if (ft_isdigit(str[0]))
		return (1);
	return (0);
}
/*-----------------------------------*/

/*-----------------------------------*/
int	pos_of_symb(char *str)
{
	char	*symbols;
	int		i;
	int		j;

	i = 0;
	j = 0;
	symbols = "! ~`\"()@#\\%£&*-'+={}[];:,.?/$";
	while (str[i])
	{
		j = 0;
		while (symbols[j])
		{
			if (str[i] == symbols[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_join_word2(t_token **token, t_token **new)
{
	char	*str;

	str = NULL;
	while ((*token))
	{
		while ((*token) && (*token)->type == W_SPACE)
			(*token) = (*token)->next;
		if ((*token)
			&& ((*token)->type == WORD)
			&& (*token)->next
			&& ((*token)->next->type == DOLLAR))
		{
			str = ft_strdup((*token)->data);
			(*token) = (*token)->next;
		}
		ft_join_tok2(token, &str);
		if (str)
			addback_token(new, find_type(str), ft_token_len(*new) + 1, str);
		free(str);
		str = NULL;
	}
}
/*-----------------------------------*/
