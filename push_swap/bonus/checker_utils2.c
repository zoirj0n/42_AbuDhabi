/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:36:57 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/03 20:36:58 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_duplicate(int *array, int maxindex)
{
	int	i;
	int	j;

	i = 0;
	while (i <= maxindex)
	{
		j = i + 1;
		while (j <= maxindex)
		{
			if (array[j] == array[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_checker(t_data *data, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
	write(2, "Error\n", 6);
	exit (0);
}

void	ft_free(t_data *data)
{
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
}
