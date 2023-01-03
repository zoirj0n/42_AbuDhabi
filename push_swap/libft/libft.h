/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:36:52 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/03 20:36:53 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2, int flag);
#endif
