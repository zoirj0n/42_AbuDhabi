/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:30 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:31 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*----------------------------------------------*/
t_token	*make_new2_line(t_token *new)
{
	t_token	*new2;
	char	*str;

	str = NULL;
	new2 = NULL;
	while (new)
	{
		if (is_new_line(new->data) && valid_pos_nline(new))
		{
			str = ft_make_new_line(&new);
			addback_token(&new2, find_type(str), ft_token_len(new2) + 1, str);
			if (new)
				new = new->next;
			free(str);
		}
		else
		{
			addback_token(&new2, find_type(new->data),
				ft_token_len(new2) + 1, new->data);
			new = new->next;
		}
	}
	return (new2);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	ft_new_token1(t_token **tokens, t_token **new_token)
{
	t_token	*tmp;
	t_token	*new;
	t_token	*new2;

	new = NULL;
	new2 = NULL;
	tmp = *tokens;
	if (!check_quotes(tmp) || !check_last_token(tmp))
		return (0);
	tmp = *tokens;
	while (tmp)
	{
		ft_convert(&tmp, &new);
		if (tmp && (tmp->type != S_QUOTE || tmp->type != D_QUOTE))
			tmp = tmp->next;
	}
	if ((new) && new->next && is_new_line(new->next->data))
	{
		new2 = make_new2_line(new);
		ft_destroy_tokens(&new);
		(*new_token) = new2;
	}
	else
		(*new_token) = new;
	return (1);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	ft_no_quotes(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == S_QUOTE || tmp->type == D_QUOTE)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
int	ft_make_tokens(t_token **tokens, char *cmd, t_token **new_tokens)
{
	(*tokens) = ft_lexer(cmd);
	if (valid_pipe_type(*tokens))
	{
		if (!ft_no_quotes(*tokens))
		{
			if (ft_new_token1(tokens, new_tokens))
				return (1);
			else
				return (0);
		}
		else
		{
			(*new_tokens) = ft_word(tokens);
			return (1);
		}
	}
	return (0);
}
/*----------------------------------------------*/

/*----------------------------------------------*/
t_token	*ft_parser(char *cmd, char **env, int *err)
{
	t_token	*tokens;
	t_token	*new_tokens;

	(void)env;
	tokens = NULL;
	new_tokens = NULL;
	if (ft_make_tokens(&tokens, cmd, &new_tokens))
	{
		if (valid_redir(new_tokens))
		{
			ft_syntax_err(&tokens, &new_tokens, &err);
			return (NULL);
		}
	}
	else
	{
		ft_syntax_err(&tokens, &new_tokens, &err);
		return (NULL);
	}
	if (tokens)
		ft_destroy_tokens(&tokens);
	return (new_tokens);
}
/*----------------------------------------------*/
