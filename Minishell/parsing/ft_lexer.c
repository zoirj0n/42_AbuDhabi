/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:23 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:24 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*-------------------------------------------*/
int	ft_get_type(char *data, int i)
{
	int	type;

	type = 0;
	if (data[i] == '<' && data[i + 1] == '<')
		type = D_LESS;
	else if (data[i] == '>' && data[i + 1] == '>')
		type = D_GREAT;
	else
		type = ft_type(data[i]);
	return (type);
}
/*-------------------------------------------*/

/*-------------------------------------------*/
char	*ft_get_data(char *cmd, int i, int len)
{
	char	*data;
	int		j;

	j = 0;
	data = NULL;
	data = (char *) malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		data[j] = cmd[i];
		j++;
		i++;
	}
	data[j] = '\0';
	return (data);
}
/*-------------------------------------------*/

/*-------------------------------------------*/
int	ft_get_token_len(char *cmd, int i)
{
	int	len;

	len = 0;
	if (ft_strchr("\t\n |<>$\\\"\'", cmd[i]))
	{
		if ((cmd[i] == '<' && cmd[i + 1] == '<')
			|| (cmd[i] == '>' && cmd[i + 1] == '>'))
			len = 2;
		else
			len = 1;
	}
	else
	{
		while (!ft_strchr("\t\n |<>$\\\"\'", cmd[i]))
		{
			i++;
			len++;
		}
	}
	return (len);
}
/*-------------------------------------------*/

/*-------------------------------------------*/
void	ft_create_tokens(t_token **tokens, char *cmd)
{
	int		i;
	int		type;
	int		len;
	char	*data;

	i = 0;
	type = 0;
	len = 0;
	data = NULL;
	while (cmd[i])
	{
		len = ft_get_token_len(cmd, i);
		data = ft_get_data(cmd, i, len);
		type = ft_get_type(cmd, i);
		addback_token(tokens, type, i, data);
		free(data);
		i += len;
	}
}
/*-------------------------------------------*/

/*-------------------------------------------*/
t_token	*ft_lexer(char *cmd)
{
	t_token	*t;

	t = NULL;
	if (!cmd)
		return (NULL);
	ft_create_tokens(&t, cmd);
	return (t);
}
/*-------------------------------------------*/