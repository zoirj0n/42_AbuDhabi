#include "libft.h"

int ft_atoi(const char *str)
{
	int index;
	unsigned int result;
	int sign;

	index = 0;
	result = 0;
	sign = 1;

	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + str[index] - 48;
		index++;
	}
	if (result > 2147483648 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (0);
	return (result * sign);
}
