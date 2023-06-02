/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:23 by ivaliev           #+#    #+#             */
/*   Updated: 2023/02/17 21:28:24 by ivaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (arg <= 'z' && arg >= 'a')
		return (1);
	else if (arg <= 'Z' && arg >= 'A')
		return (1);
	else if (arg <= '9' && arg >= '0')
		return (1);
	else
		return (0);
}
