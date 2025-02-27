/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:04 by roversch          #+#    #+#             */
/*   Updated: 2025/02/27 17:18:55 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	map_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(map[0]) * 128 - 128;
	while (map[i])
		i++;
	game->map_heigth = i * 128;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**read_map(char *argv_map)
{
	int		i;
	int		fd;
	int		lines;
	char	**map;
	char	*temp;

	lines = 0;
	fd = open(argv_map, O_RDONLY);
	while ((temp = get_next_line(fd)) != NULL)
	{
		lines++;
		free(temp);
	}
	close(fd);
	map = malloc(sizeof(char *) * (lines + 1));
	fd = open(argv_map, O_RDONLY);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

// char	**read_map(char *argv_map)
// {
// 	int		i;
// 	int		fd;
// 	int		lines;
// 	char	**map;
// 	char	*temp;

// 	lines = 0;
// 	fd = open(argv_map, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	while ((temp = get_next_line(fd)) != NULL)
// 	{
// 		lines++;
// 		free(temp);
// 	}
// 	close(fd);
// 	map = malloc(sizeof(char *) * (lines + 1));
// 	if (!map)
// 		return (0);
// 	fd = open(argv_map, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		free(map);
// 		return (0);
// 	}
// 	i = 0;
// 	while (i < lines)
// 	{
// 		map[i] = get_next_line(fd);
// 		if (!map[i])
// 		{
// 			free_map(map);
// 			close(fd);
// 			return (0);
// 		}
// 		printf("%s", map[i]);
// 		i++;
// 	}
// 	map[i] = NULL;
// 	close(fd);
// 	return (map);
// }
