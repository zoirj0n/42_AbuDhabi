/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:39 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:28:40 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	if (!alst || !(*alst))
	{
		*alst = new;
		return ;
	}
	l = *alst;
	while (l->next)
		l = l->next;
	l->next = new;
}
