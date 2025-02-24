#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width, game->map_heigth, "so_long", false); //check !fail
	get_textures(game);
	get_images(game);
	// draw_map(game, game->img);
	draw_floor(game);
	ft_player(game);
	mlx_key_hook(game->mlx, ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
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
	map_size(&game, game.map);
	init_game(&game);
	return (0);
}
