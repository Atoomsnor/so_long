/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:57 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 15:11:18 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_empty(char **map)
{
	if (map[0])
		return (TRUE);
	return (FALSE);
}

int	check_rectangle(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	check_characters(char **map, int exit, int player, int collect)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MAP_EXIT)
				exit++;
			else if (map[y][x] == MAP_PLAYER)
				player++;
			else if (map[y][x] == MAP_COLLECT)
				collect++;
			else if (!(map[y][x] == MAP_FLOOR || map[y][x] == MAP_WALL
				|| map[y][x] == MAP_PLAYER || map[y][x] == MAP_COLLECT
				|| map[y][x] == MAP_EXIT || map[y][x] == '\n'))
				return (FALSE);
			x++;
		}
	}
	if (exit != 1 || player != 1 || collect == 0)
		return (FALSE);
	return (TRUE);
}

int	check_walls(char **map)
{
	size_t	i;
	size_t	width;
	size_t	heigth;

	i = 0;
	width = ft_strlen(map[0]) - 1;
	heigth = 0;
	while (map[heigth])
		heigth++;
	while (i < width)
	{
		if (map[0][i] != MAP_WALL || map[heigth - 1][i] != MAP_WALL)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < heigth)
	{
		if (map[i][0] != MAP_WALL || map[i][width - 1] != MAP_WALL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_map(char **map)
{
	int	exit;
	int	player;
	int	collect;

	exit = 0;
	player = 0;
	collect = 0;
	if (check_empty(map) == FALSE)
		return (ft_printf("Error\nMap is empty\n"), FALSE);
	if (check_characters(map, exit, player, collect) == FALSE)
		return (ft_printf("Error\nMap has invalid characters\n"), FALSE);
	if (check_rectangle(map) == FALSE)
		return (ft_printf("Error\nMap is not rectangle\n"), FALSE);
	if (check_walls(map) == FALSE)
		return (ft_printf("Error\nMap is not surrounded by walls\n"), FALSE);
	return (TRUE);
}
