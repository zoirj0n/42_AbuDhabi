/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:34 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:35 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*--------------------------------------------*/
void	to_last_comd(t_comd **comd)
{
	while ((*comd) && (*comd)->next)
		(*comd) = (*comd)->next;
}
/*--------------------------------------------*/

/*--------------------------------------------*/
t_comd	*create_comd(char *str)
{
	t_comd	*comd;

	comd = (t_comd *)malloc(sizeof(t_comd));
	if (!comd)
		return (NULL);
	comd->next = NULL;
	comd->prev = NULL;
	comd->data = ft_strdup(str);
	return (comd);
}
/*--------------------------------------------*/

/*--------------------------------------------*/
void	add_back_comd(t_comd **comd, char *str)
{
	t_comd	*tmp;
	t_comd	*new;

	tmp = *comd;
	to_last_comd(comd);
	new = create_comd(str);
	(*comd)->next = new;
	new->prev = (*comd);
	*comd = tmp;
}
/*--------------------------------------------*/

/*--------------------------------------------*/
void	ft_make_comd_part(t_token *tmp, t_comd **comd)
{
	if (tmp->prev
		&& tmp->prev->type != LESS
		&& tmp->prev->type != D_LESS
		&& tmp->prev->type != GREAT
		&& tmp->prev->type != D_GREAT)
	{
		if (!(*comd))
			(*comd) = create_comd(tmp->data);
		else
			add_back_comd(comd, tmp->data);
	}
	else if (!tmp->prev)
	{
		if (!(*comd))
			(*comd) = create_comd(tmp->data);
		else
			add_back_comd(comd, tmp->data);
	}
}
/*--------------------------------------------*/

/*--------------------------------------------*/
t_comd	*ft_make_comd(t_token **token)
{
	t_comd	*comd;
	t_token	*tmp;

	tmp = *token;
	comd = NULL;
	while (tmp)
	{
		if (tmp && tmp->type != PIPE)
		{
			if (tmp->type == WORD || tmp->type == W_SPACE)
				ft_make_comd_part(tmp, &comd);
		}
		if (tmp->type == PIPE)
		{
			break ;
		}
		tmp = tmp->next;
	}
	return (comd);
}
/*--------------------------------------------*/