/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:25 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:28:26 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (character <= 'Z' && character >= 'A')
	{
		return (1);
	}
	else if (character <= 'z' && character >= 'a')
	{
		return (1);
	}
	else
		return (0);
}
