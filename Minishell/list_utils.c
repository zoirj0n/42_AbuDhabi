/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:13 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:28:43 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_delete_first_node(t_env **head, t_env *temp, char *name)
{
	if (ft_strcmp(temp->name, name) == 0)
	{
		*head = temp->next;
		free(temp->name);
		free(temp->value);
		free(temp);
		return (1);
	}
	return (0);
}

void	ft_delete_from_list(t_env **head, char *name)
{
	t_env	*prev;
	t_env	*temp;

	temp = *head;
	if (*head == NULL)
		return ;
	if (ft_delete_first_node(head, temp, name))
	{
		printf("world %s\n", name);
		return ;
	}
	while (temp != NULL && ft_strcmp(temp->name, name) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	else
	{
		prev->next = temp->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

t_env	*ft_create_node(char *name, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		if (name)
			new->name = ft_strdup(name);
		else
			new->name = NULL;
		if (value)
			new->value = ft_strdup(value);
		else
			new->value = NULL;
		new->next = NULL;
	}
	return (new);
}

void	ft_add_to_list(t_env **head, t_env *newnode)
{
	t_env	*list;

	if (!head || !newnode)
		return ;
	if (*head)
	{
		list = *head;
		while (list && list->next)
			list = list->next;
		list->next = newnode;
	}
	else
		*head = newnode;
}

t_env	*ft_search_list(t_env **head, char *name)
{
	t_env	*temp;

	temp = *head;
	if (temp == NULL)
		return (NULL);
	while ((temp->next != NULL) && ft_strcmp(temp->name, name) != 0)
		temp = temp->next;
	if (ft_strcmp(temp->name, name) != 0)
		return (NULL);
	return (temp);
}
