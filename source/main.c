/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:38 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 16:03:20 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	get_scale(game);
	put_map(game);
	put_objects(game);
	mlx_key_hook(game->mlx, move_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->txt);
	free(game->img);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nNot enough arguments\n"), FALSE);
	if (check_extension(argv[1]) == FALSE)
		return (ft_printf("Error\nWrong map extension\n"), FALSE);
	game.map = get_map(argv[1]);
	if (!game.map)
		return (FALSE);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), FALSE);
	map_size(&game, game.map);
	if (flood_solve(&game, argv[1]) == FALSE)
		return (free_map(game.map), FALSE);
	if (init_game(&game) == FALSE)
		return (free_map(game.map), FALSE);
	return (0);
}
