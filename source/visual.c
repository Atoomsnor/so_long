/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:19:57 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 16:14:04 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_textures));
	game->txt->floor = mlx_load_png("./textures/background128.png");
	game->txt->wall = mlx_load_png("./textures/wall128.png");
	game->txt->player = mlx_load_png("./textures/mouse128.png");
	game->txt->collect = mlx_load_png("./textures/cheese128.png");
	game->txt->exit = mlx_load_png("./textures/exit128.png");
	game->txt->open = mlx_load_png("./textures/open128.png");
}

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->floor = mlx_texture_to_image(game->mlx, game->txt->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->player = mlx_texture_to_image(game->mlx, game->txt->player);
	game->img->collect = mlx_texture_to_image(game->mlx, game->txt->collect);
	game->img->exit = mlx_texture_to_image(game->mlx, game->txt->exit);
	game->img->open = mlx_texture_to_image(game->mlx, game->txt->open);
	mlx_delete_texture(game->txt->floor);
	mlx_delete_texture(game->txt->wall);
	mlx_delete_texture(game->txt->player);
	mlx_delete_texture(game->txt->collect);
	mlx_delete_texture(game->txt->exit);
	mlx_delete_texture(game->txt->open);
}

void	get_scale(t_game *game)
{
	mlx_resize_image(game->img->floor, TILE, TILE);
	mlx_resize_image(game->img->wall, TILE, TILE);
	mlx_resize_image(game->img->player, TILE, TILE);
	mlx_resize_image(game->img->collect, TILE, TILE);
	mlx_resize_image(game->img->exit, TILE, TILE);
	mlx_resize_image(game->img->open, TILE, TILE);
}

void	put_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->floor,
				x * TILE, y * TILE);
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, game->img->wall,
					x * TILE, y * TILE);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, game->img->open,
					x * TILE, y * TILE);
				mlx_image_to_window(game->mlx, game->img->exit,
					x * TILE, y * TILE);
			}
			x++;
		}
		y++;
	}
}

void	put_objects(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MAP_PLAYER)
				mlx_image_to_window(game->mlx, game->img->player,
					x * TILE, y * TILE);
			if (game->map[y][x] == MAP_COLLECT)
			{
				mlx_image_to_window(game->mlx, game->img->collect,
					x * TILE, y * TILE);
				game->collect_amount++;
			}
			x++;
		}
		y++;
	}
}
