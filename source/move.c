/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:19:12 by roversch          #+#    #+#             */
/*   Updated: 2025/02/27 17:22:05 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[PLAYER_Y / TILE - 1][PLAYER_X / TILE] != MAP_WALL)
	{
		PLAYER_Y -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[PLAYER_Y / TILE + 1][PLAYER_X / TILE] != MAP_WALL)
	{
		PLAYER_Y += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE - 1] != MAP_WALL)
	{
		PLAYER_X -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE + 1] != MAP_WALL)
	{
		PLAYER_X += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_EXIT)
			exit_found(game);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			move_up(game);
		else if (keydata.key == MLX_KEY_DOWN)
			move_down(game);
		else if (keydata.key == MLX_KEY_LEFT)
			move_left(game);
		else if (keydata.key == MLX_KEY_RIGHT)
			move_right(game);
	}
}
