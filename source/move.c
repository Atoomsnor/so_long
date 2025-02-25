#include "so_long.h"

void ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{	
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			game->img->player->instances[0].y -= 128;
		else if (keydata.key == MLX_KEY_DOWN)
			game->img->player->instances[0].y += 128;
		else if (keydata.key == MLX_KEY_LEFT)
			game->img->player->instances[0].x -= 128;
		else if (keydata.key == MLX_KEY_RIGHT)
			game->img->player->instances[0].x += 128;
	}
}