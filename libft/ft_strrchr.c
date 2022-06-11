#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int main ()
// {
// 	printf("%s", ft_strrchr("islom valiev",'m'));
// }
// bu funksiya bizga chappasiga keladi va bizga ohiridan 
// boshlab suragan narsamizdi chiara 
// out :m valiev buladi