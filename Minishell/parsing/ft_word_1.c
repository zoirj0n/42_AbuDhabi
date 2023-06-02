/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:50 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:51 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------*/
int	find_type(char *str)
{
	if (!str)
		return (WORD);
	if (!ft_strcmp(str, ">"))
		return (GREAT);
	else if (!ft_strcmp(str, ">>"))
		return (D_GREAT);
	else if (!ft_strcmp(str, "<"))
		return (LESS);
	else if (!ft_strcmp(str, "<<"))
		return (D_LESS);
	else if (!ft_strcmp(str, "|"))
		return (PIPE);
	else if (!ft_strcmp(str, "\\"))
		return (BACKSLASH);
	else
		return (WORD);
}
/*-----------------------------------*/

/*-----------------------------------*/
int	valid_pos_nline(t_token *token)
{
	token = token->prev;
	while (token)
	{
		if (token->type == WORD)
			break ;
		token = token->prev;
	}
	if (token && !token->prev)
		return (1);
	else
		return (0);
}
/*-----------------------------------*/

/*-----------------------------------*/
int	is_valid_new_line(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/*-----------------------------------*/
int	is_new_line(char *str)
{
	if (!ft_strncmp(str, "-n", 2))
	{
		if (is_valid_new_line(str))
			return (1);
	}
	return (0);
}
/*-----------------------------------*/

/*---------------------------------------*/
char	*ft_make_new_line(t_token **token)
{
	char	*str;

	str = ft_strdup("-n");
	while (*token)
	{
		if (!is_new_line((*token)->data) && (*token)->type != W_SPACE)
			break ;
		(*token) = (*token)->next;
	}
	if (*token)
		(*token) = (*token)->prev;
	return (str);
}
/*---------------------------------------*/
