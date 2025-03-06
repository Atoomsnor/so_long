/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:32:02 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 15:15:04 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_player(char **map, int pos_y, int pos_x)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MAP_PLAYER)
			{
				if (pos_y > 0)
					return ((pos_x = x), pos_x);
				return ((pos_y = y), pos_y);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	flood_map(t_game *game, int pos_y, int pos_x)
{
	if (!(pos_y < 1 || pos_y > game->map_heigth
			|| pos_x < 1 || (size_t)pos_x > game->map_width
			|| game->tempmap[pos_y][pos_x] == '1'
		|| game->tempmap[pos_y][pos_x] == 'X'))
	{
		game->tempmap[pos_y][pos_x] = 'X';
		flood_map(game, pos_y - 1, pos_x);
		flood_map(game, pos_y + 1, pos_x);
		flood_map(game, pos_y, pos_x - 1);
		flood_map(game, pos_y, pos_x + 1);
	}
}

int	flood_check(char **tempmap)
{
	int	y;
	int	x;

	y = 0;
	while (tempmap[y])
	{
		x = 0;
		while (tempmap[y][x])
		{
			if (!(tempmap[y][x] == MAP_WALL || tempmap[y][x] == 'X'
				|| tempmap[y][x] == MAP_FLOOR || tempmap[y][x] == '\n'))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	flood_solve(t_game *game, char *argv)
{
	int	pos_y;
	int	pos_x;

	pos_y = 0;
	pos_x = 0;
	game->tempmap = get_map(argv);
	pos_y = flood_player(game->tempmap, pos_y, pos_x);
	pos_x = flood_player(game->tempmap, pos_y, pos_x);
	flood_map(game, pos_y, pos_x);
	if (flood_check(game->tempmap) == FALSE)
	{
		free_map(game->tempmap);
		return (ft_printf("Error\nMap is not solvable\n"), FALSE);
	}
	free_map(game->tempmap);
	return (TRUE);
}
