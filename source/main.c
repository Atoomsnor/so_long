/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:38 by roversch          #+#    #+#             */
/*   Updated: 2025/03/04 18:10:53 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->collect_count = 0;
	game->collect_amount = 0;
	game->mlx = mlx_init(game->map_width, game->map_heigth, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	get_textures(game);
	get_images(game);
	scale_images(game);
	put_map(game);
	put_objects(game);
	mlx_key_hook(game->mlx, ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->txt);
	free(game->img);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nNot enough arguments\n"), 1);
	if (check_extension(argv[1]) == FALSE)
		return (ft_printf("Error\nWrong map extension\n"), 1);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	map_size(&game, game.map);
	if (flood_solve(&game, argv[1]) == FALSE)
		return (1);
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}
