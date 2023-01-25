/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:39:02 by zosobiro          #+#    #+#             */
/*   Updated: 2023/01/25 13:09:44 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_check_file_extension(char *file)
{
	char	*extension;
	char	*right_extension;
	int		file_name_length;
	int		i;

	file_name_length = 0;
	while (file[file_name_length] != '\0')
		file_name_length++;
	file_name_length = file_name_length - 4;
	right_extension = ".ber";
	extension = malloc(sizeof(char) * 4);
	i = 0;
	while (file[file_name_length] != '\0' && i < 4)
	{
		extension[i] = file[file_name_length];
		file_name_length++;
		i++;
	}
	extension[i] = '\0';
	if (ft_strcmp(extension, right_extension) == 0)
		return (1);
	else
		return (0);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	if (!ft_check_file_extension(argv[1]))
	{
		printf("\e[31m\e[1mError\n File extension is not Valid\n");
		exit_point(game);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
