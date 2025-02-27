#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->collect_count = 0;
	game->collect_amount = 0;
	game->mlx = mlx_init(game->map_width, game->map_heigth, "so_long", false); //check !fail
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
	// (void) argv;

	game.map = read_map(argv[1]);
	if (!game.map)
	{
		printf("Failed to load map\n");
		return (1);
	}
	if (check_rectangle(game.map) == 1)
		return(free_map(game.map), 1);
	map_size(&game, game.map);
	//make sure map is solvable with flood?
	init_game(&game);
	return (0);
}
