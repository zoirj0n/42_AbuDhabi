#include "ft_printf.h"

int	ft_num_len(unsigned	int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*number;
	int		len;

	len = ft_num_len(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len] = '\0';
	while (n != 0)
	{
		number[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (number);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*number;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		number = ft_uitoa(n);
		print_length += ft_printstr(number);
		free(number);
	}
	return (print_length);
}
