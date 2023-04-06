#include "ft_printf.h"

int	ft_hex_len(unsigned	int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_put_hex(number / 16, format);
		ft_put_hex(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((number - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(number, format);
	return (ft_hex_len(number));
}
