#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s [i]);
		}
		i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

// int main ()
// {
// 	char i[] = "hello";
// 	printf("%s",ft_strchr(i, 'l'));
// }
// bu bizga "l" dan boshla hamma harflar chiqaradi 
// bunda biz  int char oziga l di iscii qib oladi
// keyin unga qushadi
