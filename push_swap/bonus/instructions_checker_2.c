#include "checker.h"

void	pa(t_data *data)
{
	if (data->topb >= 0)
	{
		data->a[data->topa + 1] = data->b[data->topb];
		data->topa += 1;
		data->topb -= 1;
	}
}

void	pb(t_data *data)
{
	if (data->topa >= 0)
	{
		data->b[data->topb + 1] = data->a[data->topa];
		data->topb += 1;
		data->topa -= 1;
	}	
}

void	sa(t_data *data)
{
	int	temp;

	if (data->topa > 0)
	{
		temp = data->a[data->topa];
		data->a[data->topa] = data->a[data->topa - 1];
		data->a[data->topa - 1] = temp;
	}
}

void	sb(t_data *data)
{
	int	temp;

	if (data->topb > 0)
	{
		temp = data->b[data->topb];
		data->b[data->topb] = data->b[data->topb - 1];
		data->b[data->topb - 1] = temp;
	}
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
