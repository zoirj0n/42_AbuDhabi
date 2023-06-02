/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:24 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:25 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*--------------------------------------------*/
void	to_last_allput(t_allput **allput)
{
	while ((*allput) && (*allput)->next)
		(*allput) = (*allput)->next;
}
/*--------------------------------------------*/

/*----------------------------------------------*/
char	**ft_tab_put(t_token **token)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char) * (2 + 1));
	if (!tab)
		return (NULL);
	while (*token && (*token)->type != WORD)
	{
		tab[i] = ft_strdup((*token)->data);
		i++;
		(*token) = (*token)->next;
		if ((*token) && (*token)->type == WORD)
		{
			tab[i] = ft_strdup((*token)->data);
			break ;
		}
	}
	tab[i] = NULL;
	return (tab);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_comd	*ft_make_put(t_token **token)
{
	t_comd	*put;

	put = NULL;
	if (*token && (*token)->type != WORD)
	{
		put = create_comd((*token)->data);
		(*token) = (*token)->next;
		add_back_comd(&put, (*token)->data);
	}
	return (put);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_allput	*create_allput(t_token **token)
{
	t_allput	*allput;

	allput = (t_allput *)malloc(sizeof(t_allput));
	if (!allput)
		return (NULL);
	allput->next = NULL;
	allput->prev = NULL;
	allput->data = ft_make_put(token);
	allput->infile = -1;
	allput->outfile = -1;
	return (allput);
}
/*----------------------------------------------*/
