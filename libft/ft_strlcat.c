#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	sd;
	size_t	sc;

	sc = ft_strlen(src);
	sd = ft_strlen(dst);
	i = 0;
	j = sd;
	if (sd < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && sd + i < dstsize - 1)
		{	
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (sd >= dstsize)
	{
		sd = dstsize;
	}
	return (sd + sc);
}

// int main()
// {
// 	char	dest[100] = "yoyoyo ";
// 	ft_strlcat(dest, "hello islom\n", 100);
// 	printf("%s", dest);
//     // printf("%zu", ft_strlcat("islom", "valiev", 1));
// }
// bu bizga kiritgan narsamizdi ohiridan qushib beradi