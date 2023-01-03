#include "checker.h"

int	ft_atoi(t_data *data, char *str, char **av)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		ft_free_checker(data, av);
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
		if ((res > 2147483647 && sign == 1)
			|| ((res > 2147483648) && (sign == -1)))
			ft_free_checker(data, av);
	}
	if ((!ft_isdigit(str[i]) && str[i]) || i > 12)
		ft_free_checker(data, av);
	return (res * sign);
}

int	ft_is_sorted(t_data *data)
{
	int	i;

	i = data->topa;
	while (i != 0)
	{
		if (data->a[i] < data->a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}

void	double_check_arg(t_data *data, char *str)
{
	int		i;
	char	**args;

	args = ft_split(str, ' ');
	free (str);
	initialize(data, args);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	error(t_data *data)
{
	free (data->a);
	free (data->b);
	write(2, "Error\n", 6);
	exit (0);
}
