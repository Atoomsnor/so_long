/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:19:12 by roversch          #+#    #+#             */
/*   Updated: 2025/03/03 18:32:05 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	y;
	int	x;

	y = game->img->player->instances->y / TILE;
	x = game->img->player->instances->x / TILE;
	if (game->map[y - 1][x] != MAP_WALL)
	{
		game->img->player->instances->y -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[y - 1][x] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[y - 1][x] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_down(t_game *game)
{
	int	y;
	int	x;

	y = game->img->player->instances->y / TILE;
	x = game->img->player->instances->x / TILE;
	if (game->map[y + 1][x] != MAP_WALL)
	{
		game->img->player->instances->y += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[y + 1][x] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[y + 1][x] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = game->img->player->instances->y / TILE;
	x = game->img->player->instances->x / TILE;
	if (game->map[y][x - 1] != MAP_WALL)
	{
		game->img->player->instances->x -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[y][x - 1] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[y][x - 1] == MAP_EXIT)
			exit_found(game);
	}
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	y = game->img->player->instances->y / TILE;
	x = game->img->player->instances->x / TILE;
	if (game->map[y][x + 1] != MAP_WALL)
	{
		game->img->player->instances->x += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		if (game->map[y][x + 1] == MAP_COLLECT)
			collect_found(game);
		else if (game->map[y][x + 1] == MAP_EXIT)
			exit_found(game);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void* param)
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
