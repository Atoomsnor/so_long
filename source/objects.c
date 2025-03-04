/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:42:35 by roversch          #+#    #+#             */
/*   Updated: 2025/03/04 12:32:24 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_found(t_game *game)
{
	int	i;
	int	y;
	int	x;

	y = game->img->player->instances->y;
	x = game->img->player->instances->x;
	i = 0;
	while (i < game->collect_amount)
	{
		if ((y == game->img->collect->instances[i].y)
			&& (x == game->img->collect->instances[i].x))
		{
			game->img->collect->instances[i].enabled = false;
			game->map[y / TILE][x / TILE] = MAP_FLOOR;
			game->collect_count++;
			if (game->collect_count == game->collect_amount)
				game->img->exit->instances[0].enabled = false;	
			return ;
		}
		i++;
	}
}

void	exit_found(t_game *game)
{
	if (game->collect_count == game->collect_amount)
	{
		ft_printf("Succes\n");
		mlx_close_window(game->mlx);
	}
}
