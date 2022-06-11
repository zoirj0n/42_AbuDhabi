#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*i;

	if (count != 0 && size != 0 && count > SIZE_MAX / size)
		return (NULL);
	i = malloc(count * size);
	if (i == NULL)
		return (NULL);
	ft_bzero(i, count * size);
	return (i);
}		

// bu funksiya bizga har bitta baytdi 0 ga aylantirib qaytardi