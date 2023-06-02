/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:56 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:57 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-----------------------------------*/
void	ft_join_part2(t_token **token, char **str)
{
	if (*token && is_new_line((*token)->data)
		&& !is_new_line((*token)->prev->data)
		&& valid_pos_nline(*token))
		(*str) = ft_make_new_line(token);
	else
	{
		if (*token)
			(*str) = strdup((*token)->data);
	}
	if (*token)
		(*token) = (*token)->next;
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_join_str1(char **tmp2, char **tmp3, char **tmp1, char **str)
{
	if (!(*tmp2))
	{
		(*tmp3) = (*str);
		((*str)) = ft_strjoin((*tmp3), (*tmp1));
		free((*tmp3));
		(*tmp3) = NULL;
	}
	else
	{
		(*tmp3) = (*str);
		(*str) = ft_strjoin((*tmp3), (*tmp2));
		free((*tmp3));
		(*tmp3) = NULL;
		(*tmp3) = (*str);
		(*str) = ft_strjoin((*tmp3), (*tmp1));
		free((*tmp3));
		(*tmp3) = NULL;
	}
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_expand11(t_token **token, char **str)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	int		pos1;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	pos1 = pos_of_symb((*token)->data);
	tmp1 = ft_substr((*token)->data, 0, pos1);
	tmp2 = ft_find_var(tmp1);
	free(tmp1);
	tmp1 = NULL;
	tmp1 = ft_substr((*token)->data, pos1, ft_strlen((*token)->data));
	ft_join_str1(&tmp2, &tmp3, &tmp1, str);
	free(tmp2);
	free(tmp1);
	tmp2 = NULL;
	tmp1 = NULL;
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_join_str2(char *string, char **str)
{
	char	*tmp1;
	char	*tmp2;
	int		pos1;

	tmp1 = NULL;
	tmp2 = NULL;
	pos1 = pos_of_symb(string);
	tmp1 = ft_substr(string, 0, pos1);
	tmp2 = ft_find_var(tmp1);
	free(tmp1);
	tmp1 = NULL;
	tmp1 = ft_substr(string, pos1, ft_strlen(string));
	if (tmp2)
		(*str) = ft_strjoin(tmp2, tmp1);
	else
		(*str) = ft_strdup(tmp1);
	free(tmp1);
	tmp1 = NULL;
	free(tmp2);
	tmp2 = NULL;
}
/*-----------------------------------*/

/*-----------------------------------*/
void	ft_expand2(t_token **token, char **str)
{
	if (ft_isalpha((*token)->data[0]))
	{
		ft_join_str2((*token)->data, str);
		(*token) = (*token)->next;
	}
	else
	{
		(*str) = ft_strjoin((*token)->prev->data, (*token)->data);
		(*token) = (*token)->next;
	}
}
/*-----------------------------------*/
