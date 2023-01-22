#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 1)
		return ;
	write(fd, &c, 1);
}
