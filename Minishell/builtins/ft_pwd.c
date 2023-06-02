/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:27:33 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:43 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(int out_fd)
{
	char	cwd[200];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(out_fd, cwd, ft_strlen(cwd));
		write(out_fd, "\n", 1);
	}
	else
		write(out_fd, "getcwd() error\n", ft_strlen("getcwd() error\n"));
}
