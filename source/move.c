#include "so_long.h"

void	move_up(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y - 1][new_x] != MAP_WALL)
	{
		// if (game->map[new_y - 1][new_x] == MAP_COLLECT)
		// 	ft_printf("Collect");
		// else if (game->map[new_y - 1][new_x] == MAP_EXIT)
		// 	ft_printf("Exit");
		game->img->player->instances->y -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_down(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y + 1][new_x] != MAP_WALL)
	{
		// if (game->map[new_y + 1][new_x] == MAP_COLLECT)
		// 	ft_printf("Collect");
		// else if (game->map[new_y + 1][new_x] == MAP_EXIT)
		// 	ft_printf("Exit");
		game->img->player->instances->y += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_left(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x - 1] != MAP_WALL)
	{
		// if (game->map[new_y][new_x - 1] == MAP_COLLECT)
			// collect function?
		// else if (game->map[new_y][new_x - 1] == MAP_EXIT)
			// check exit status function
		game->img->player->instances->x -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_right(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x + 1] != MAP_WALL)
	{
		// if (game->map[new_y][new_x + 1] == MAP_COLLECT)
		// 	ft_printf("Collect");
		// else if (game->map[new_y][new_x + 1] == MAP_EXIT)
		// 	ft_printf("Exit");
		game->img->player->instances->x += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	int	new_y;
	int	new_x;

	game = param;
	new_y = game->img->player->instances->y / TILE;
	new_x = game->img->player->instances->x / TILE;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{	
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			move_up(game, new_y, new_x);
		else if (keydata.key == MLX_KEY_DOWN)
			move_down(game, new_y, new_x);
		else if (keydata.key == MLX_KEY_LEFT)
			move_left(game, new_y, new_x);
		else if (keydata.key == MLX_KEY_RIGHT)
			move_right(game, new_y, new_x);
	}
}
