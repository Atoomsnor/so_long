/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:38 by roversch          #+#    #+#             */
/*   Updated: 2025/03/03 14:44:38 by roversch         ###   ########.fr       */
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

	(void) argc;
	//check extension
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	map_size(&game, game.map);
	//make sure map is solvable with flood?
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}
