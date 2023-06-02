/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:33:21 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:33:22 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-------------------------------------------*/
int	ft_type(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (LESS);
	else if (c == '>')
		return (GREAT);
	else if (c == '\'')
		return (S_QUOTE);
	else if (c == '"')
		return (D_QUOTE);
	else if (c == '$')
		return (DOLLAR);
	else if (c == ' ')
		return (W_SPACE);
	else if (c == '\n')
		return (N_LINE);
	else if (c == '\\')
		return (BACKSLASH);
	else if (c == '\\')
		return (BACKSLASH);
	return (WORD);
}
/*-------------------------------------------*/
