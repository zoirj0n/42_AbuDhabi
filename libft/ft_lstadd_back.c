#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (node == NULL)
	{
		*lst = new;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
