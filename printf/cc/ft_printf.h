#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int number, const char format);
int		ft_printpercent(void);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int number);
void	ft_put_hex(unsigned int number, const char format);
int		ft_hex_len(unsigned	int number);
void	ft_putchar_fd(char c, int fd);
#endif
