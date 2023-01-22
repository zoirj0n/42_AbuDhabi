/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:35:57 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/03 20:35:58 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *data)
{
	if (data->a[2] > data->a[1] && data->a[2] < data->a[0])
		sa(data);
	else if (data->a[2] > data->a[1]
		&& data->a[2] > data->a[0] && data->a[1] < data->a[0])
		ra(data);
	else if (data->a[2] < data->a[1] && data->a[2] > data->a[0])
		rra(data);
	else if (data->a[2] < data->a[1] && data->a[2] < data->a[0])
	{
		sa(data);
		ra(data);
	}
	else if (data->a[2] > data->a[1] && data->a[2] > data->a[0])
	{
		sa(data);
		rra(data);
	}
}

void	pusha(t_data *data)
{
	while (data->topb >= 0)
		pa(data);
}	

void	ft_sort_small(t_data *data)
{
	if (data->topa == 0)
		return ;
	else if (data->topa == 1)
		sa(data);
	else if (data->topa == 2)
		ft_sort_three(data);
	else
	{
		while (data->topa > 2 && !ft_is_sorted(data))
		{
			if (ft_lowesta(data) == data->topa)
				pb(data);
			else
			{
				if (ft_lowesta(data) <= 1)
					rra(data);
				else
					ra(data);
			}
		}
		if (!ft_is_sorted(data))
			ft_sort_small(data);
		pusha(data);
	}
}

void	ft_sort_large(t_data *data)
{
	int	low;
	int	top;
	int	high;

	low = 1;
	top = data->topa;
	high = top / 2;
	while (low < top)
	{
		push(data, low, high);
		low = high;
		high = (high + (top - high) / 2) + 1;
	}
	pushback(data);
}
