/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:04 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 15:17:31 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	get_map_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(map[0]) * TILE - TILE;
	while (map[i])
		i++;
	game->map_heigth = i * TILE;
}

char	**get_lines(char *argv, int *lines)
{
	int		fd;
	char	**map;
	char	*temp;

	*lines = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp = get_next_line(fd);
	while (temp)
	{
		(*lines)++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (*lines == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (*lines + 1));
	if (!map)
		return (NULL);
	return (map);
}

char	**get_map(char *argv)
{
	int		i;
	int		fd;
	int		lines;
	char	**map;

	map = get_lines(argv, &lines);
	if (!map)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = -1;
	while (++i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
