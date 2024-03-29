#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
#include <stdio.h>
int main()
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	t_list *first = ft_lstnew(&num1);
	ft_lstadd_back(&first, ft_lstnew(&num2));
	ft_lstadd_back(&first, ft_lstnew(&num3));
	t_list *last = ft_lstlast(first);
	printf("%d\n", *(int *)last->content);
}