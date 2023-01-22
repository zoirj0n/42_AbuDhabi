/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:36:58 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/03 20:36:59 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_input(t_data *data, char **line)
{
	if (ft_strcmp(*line, "sa"))
		sa(data);
	else if (ft_strcmp(*line, "sb"))
		sb(data);
	else if (ft_strcmp(*line, "ss"))
		ss(data);
	else if (ft_strcmp(*line, "pa"))
		pa(data);
	else if (ft_strcmp(*line, "pb"))
		pb(data);
	else if (ft_strcmp(*line, "ra"))
		ra(data);
	else if (ft_strcmp(*line, "rb"))
		rb(data);
	else if (ft_strcmp(*line, "rr"))
		rr(data);
	else if (ft_strcmp(*line, "rra"))
		rra(data);
	else if (ft_strcmp(*line, "rrb"))
		rrb(data);
	else if (ft_strcmp(*line, "rrr"))
		rrr(data);
	else
		error(data);
}

void	ft_get_lines(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_check_input(data, &line);
		free(line);
		line = NULL;
	}
	if (ft_is_sorted(data) && data->topb == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	initialize(t_data *data, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
		i++;
	data->a = NULL;
	data->b = NULL;
	data->a = (int *)malloc(sizeof(int) * i);
	data->b = (int *)malloc(sizeof(int) * i);
	if (!data->a || !data->b)
		error(data);
	j = 0;
	i--;
	while (i >= 0)
		data->a[j++] = ft_atoi(data, av[i--], av);
	data->topa = j - 1;
	data->topb = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	char	*str;		
	int		flag;

	str = "";
	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	flag = 0;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i], flag);
		flag = 1;
		i++;
	}
	double_check_arg(&data, str);
	if (ft_is_duplicate(data.a, data.topa))
		error(&data);
	ft_get_lines(&data);
	ft_free(&data);
	return (0);
}
