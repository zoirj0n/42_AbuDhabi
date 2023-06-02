/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:30:53 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:30:54 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
char	*str_quoted(t_token **token, int type)
{
	char	*str;
	int		count;

	count = 0;
	str = NULL;
	while ((*token))
	{
		if ((*token) && (*token)->type == type)
		{
			count++;
			if (count == 2)
			{
				count = 0;
				*token = (*token);
				return (str);
			}
			(*token) = (*token)->next;
			join_all_str(&(*token), &str, type);
		}
		else
			(*token) = (*token)->next;
	}
	return (str);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
char	*ft_trans_str(char *str)
{
	char	*new_str;
	char	*tmp1;
	char	*tmp2;
	int		pos;

	tmp1 = NULL;
	tmp2 = NULL;
	new_str = NULL;
	pos = pos_of_symb(str);
	tmp1 = ft_substr(str, 0, pos);
	tmp2 = ft_find_var(tmp1);
	if (tmp1)
		free(tmp1);
	tmp1 = ft_substr(str, pos, ft_strlen(str));
	new_str = ft_strjoin(tmp2, tmp1);
	if (tmp1)
		free(tmp1);
	if (tmp2)
		free(tmp2);
	return (new_str);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	is_symbol(char c)
{
	char	*symbols;
	int		i;

	i = 0;
	symbols = "!~`\"()@#\\%&*-'+={}[];:,.?/$";
	while (symbols[i])
	{
		if (c == symbols[i])
			return (1);
		i++;
	}
	return (0);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
void	find_var_part(char *new_str, char **str)
{
	char	*tmp;
	int		i;
	int		len;
	int		len_var;

	tmp = NULL;
	i = 0;
	len = 0;
	len_var = 0;
	tmp = ft_strjoin(new_str, "=");
	len = ft_strlen(tmp);
	while (g_vars->env_clone[i])
	{
		if (!ft_strncmp(tmp, g_vars->env_clone[i], len))
		{
			len_var = ft_strlen(g_vars->env_clone[i]);
			*str = ft_substr(g_vars->env_clone[i], len, len_var - len);
		}
		i++;
	}
	if (tmp)
		free(tmp);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
char	*ft_find_var(char *new_str)
{
	char	*str;

	str = NULL;
	if (is_symbol(new_str[0]))
	{
		str = ft_strdup(new_str);
		return (str);
	}
	find_var_part(new_str, &str);
	return (str);
}
/*----------------------------------------------*/