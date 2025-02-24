#include "so_long.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width, game->map_heigth, "so_long", false); //check !fail
	get_textures(game);
	get_images(game);
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
	(void) argv;

	//check valid map inputs and argc
	game.map_width = 320;
	game.map_heigth = 320;
	init_game(&game);
	return (0);
}
