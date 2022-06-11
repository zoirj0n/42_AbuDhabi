#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (f != NULL && s != NULL)
	{
		i = 0;
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

// void print_char(unsigned int i, char *c)
// {
// 		write(1, c, 1);
// 	// printf("hi");
// }

// // Google function pointerss after this
// int	main()
// {
// 	ft_striteri("yo", print_char);
// }
// bu bizga 2 ta funksiya bilan ishlashga yordam beradi bu 
// yani js da call back funksiyaga uxshaydi
