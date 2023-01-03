#include "push_swap.h"

void	initialize(t_data *data, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
		i++;
	data->indexarray = (int *)malloc(sizeof(int) * i);
	data->a = (int *)malloc(sizeof(int) * i);
	data->b = (int *)malloc(sizeof(int) * i);
	if (!data->indexarray || !data->a
		|| !data->b)
		error(data);
	j = 0;
	i--;
	while (i >= 0)
	{
		data->indexarray[j] = ft_atoi(data, av[i], av);
		data->a[j++] = ft_atoi(data, av[i--], av);
	}
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
	ft_check(&data);
	return (0);
}
