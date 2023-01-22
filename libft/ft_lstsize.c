#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*element;
	int		size;

	size = 0;
	element = lst;
	while (element != NULL)
	{
		element = element->next;
		size++;
	}
	return (size);
}
