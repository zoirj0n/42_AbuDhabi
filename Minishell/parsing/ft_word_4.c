/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:59 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:32:00 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------*/
void	ft_expand3(t_token **token, char **str)
{
	char	*tmp3;
	char	*tmp;

	tmp3 = NULL;
	tmp = NULL;
	if (*str)
	{
		tmp3 = *str;
		tmp = ft_substr((*token)->data, 1, ft_strlen((*token)->data));
		(*str) = ft_strjoin(tmp3, tmp);
		(*token) = (*token)->next;
		free(tmp);
		tmp = NULL;
		free(tmp3);
		tmp3 = NULL;
	}
	else
	{
		(*str) = ft_substr((*token)->data, 1, ft_strlen((*token)->data));
		(*token) = (*token)->next;
	}
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_expand1(t_token **token, char **str)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (ft_isalpha((*token)->data[0]))
		ft_expand11(token, str);
	else
	{
		tmp1 = *str;
		tmp2 = ft_strjoin(tmp1, (*token)->prev->data);
		*str = ft_strjoin(tmp2, (*token)->data);
		free(tmp2);
		free(tmp1);
		tmp2 = NULL;
		tmp1 = NULL;
	}
	(*token) = (*token)->next;
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_expand4(t_token **token, char **str)
{
	char	*tmp3;
	char	*tmp;

	tmp3 = NULL;
	tmp = NULL;
	if (*str)
	{
		tmp3 = *str;
		tmp = ft_find_var((*token)->data);
		if (tmp)
		{
			(*str) = ft_strjoin(tmp3, tmp);
			free(tmp);
			tmp = NULL;
			free(tmp3);
			tmp3 = NULL;
		}
		(*token) = (*token)->next;
	}
	else if (*token)
	{
		(*str) = ft_find_var((*token)->data);
		(*token) = (*token)->next;
	}
}
/*-----------------------------------*/
