/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:42:35 by roversch          #+#    #+#             */
/*   Updated: 2025/02/27 14:40:16 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_found(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->collect_amount;
	while (i < count) //make sure to put failchek for 0collcts
	{
		if ((PLAYER_Y == game->img->collect->instances[i].y)
			&& (PLAYER_X == game->img->collect->instances[i].x))
		{
			game->img->collect->instances[i].enabled = false;
			count--;
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
