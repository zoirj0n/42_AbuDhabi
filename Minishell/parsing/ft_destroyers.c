/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroyers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:02 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:06 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
void	ft_destroy_tokens(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = (*token)->next;
		if (*token && (*token)->data)
		{
			free((*token)->data);
			(*token)->data = NULL;
		}
		free(*token);
		(*token) = tmp;
	}
}
/*---------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_comd(t_comd **comd)
{
	t_comd	*tmp;

	while (*comd)
	{
		tmp = (*comd)->next;
		if (*comd)
		{
			free((*comd)->data);
			(*comd)->data = NULL;
		}
		free(*comd);
		(*comd) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_allput(t_allput **allput)
{
	t_allput	*tmp;

	while (*allput)
	{
		tmp = (*allput)->next;
		if (*allput)
		{
			ft_destroy_comd(&(*allput)->data);
			(*allput)->data = NULL;
		}
		free(*allput);
		(*allput) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_cmd2(t_cmd2 **cmd)
{
	t_cmd2	*tmp;

	tmp = NULL;
	while (*cmd)
	{
		tmp = (*cmd)->next;
		ft_destroy_comd(&(*cmd)->comd);
		ft_destroy_allput(&(*cmd)->input);
		ft_destroy_allput(&(*cmd)->output);
		free(*cmd);
		(*cmd) = tmp;
	}
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	ft_destroy_cmds2(t_cmds2 **cmds)
{
	ft_destroy_cmd2(&(*cmds)->cmd);
	free(*cmds);
}
/*----------------------------------------------*/