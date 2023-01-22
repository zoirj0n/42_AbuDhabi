
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (node == NULL)
		*lst = new;
	else
	{
		new->next = node;
		*lst = new;
	}
}
