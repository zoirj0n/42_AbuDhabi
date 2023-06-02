/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:27 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:28 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	add_back_allput(t_allput **allput, t_token **token)
{
	t_allput	*tmp;
	t_allput	*new;

	tmp = *allput;
	to_last_allput(allput);
	new = create_allput(token);
	(*allput)->next = new;
	new->prev = (*allput);
	*allput = tmp;
}
/*--------------------------------------------*/

/*----------------------------------------------*/
t_allput	*ft_make_input(t_token **token)
{
	t_allput	*input;
	t_token		*tmp;

	input = NULL;
	tmp = *token;
	while (tmp)
	{
		if (tmp && tmp->type != PIPE)
		{
			if (tmp->type == LESS || tmp->type == D_LESS)
			{
				if (!input)
					input = create_allput(&tmp);
				else
					add_back_allput(&input, &tmp);
			}
		}
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	return (input);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_allput	*ft_make_output(t_token **token)
{
	t_allput	*output;
	t_token		*tmp;

	output = NULL;
	tmp = *token;
	while (tmp)
	{
		if (tmp && tmp->type != PIPE)
		{
			if (tmp->type == GREAT || tmp->type == D_GREAT)
			{
				if (!output)
					output = create_allput(&tmp);
				else
					add_back_allput(&output, &tmp);
			}
		}
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	(*token) = tmp;
	return (output);
}
/*----------------------------------------------*/