/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:31:19 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:31:20 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*------------------------------*/
int	copy_env_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}
/*------------------------------*/

/*------------------------------*/
void	clone_env_part(t_env *env, char **clone_env)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (env)
	{
		tmp = ft_strjoin(env->name, "=");
		if (env->value)
			clone_env[i] = ft_strjoin(tmp, env->value);
		else
			clone_env[i] = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		i++;
		env = env->next;
	}
	clone_env[i] = NULL;
}
/*------------------------------*/

/*------------------------------*/
char	**make_clone_env(t_env *copy_env)
{
	char	**clone_env;
	int		len;
	t_env	*copy_temp;

	copy_temp = copy_env;
	clone_env = NULL;
	len = copy_env_len(copy_temp);
	clone_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (clone_env == NULL)
		return (NULL);
	clone_env_part(copy_temp, clone_env);
	return (clone_env);
}
/*-------------------------------------------------------*/

/*----------------------------------------------*/
void	ft_syntax_err(t_token **tok, t_token **new, int **err)
{
	if (*tok)
		ft_destroy_tokens(tok);
	if (*new)
		ft_destroy_tokens(new);
	printf("Error: invalid syntax\n");
	*(*err) = 1;
}
/*----------------------------------------------*/
