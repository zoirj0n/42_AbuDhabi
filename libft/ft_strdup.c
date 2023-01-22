#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int main ()
// {
// 	printf(" %s", ft_strdup(""));
// }
// bu funcsiya bizga strda ohirida tugovchi '\0' 
//bulmaydi shuni qushib beradi bizga 