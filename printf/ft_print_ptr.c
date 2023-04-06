#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t number)
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

static void	ft_put_ptr(uintptr_t number)
{
	if (number >= 16)
	{
		ft_put_ptr(number / 16);
		ft_put_ptr(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
			ft_putchar_fd((number - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
