#include "so_long.h"

void	move_up(t_game *game, int step_y, int step_x)
{
	if (game->map[step_y - 1][step_x] != MAP_WALL)
	{
		// if (game->map[step_y - 1][step_x] == MAP_COLLECT)
		// 	collect_pickup(game);
		// else if (game->map[step_y - 1][step_x] == MAP_EXIT)
		// 	ft_printf("Exit");
		PLAYER_Y -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_down(t_game *game, int step_y, int step_x)
{
	if (game->map[step_y + 1][step_x] != MAP_WALL)
	{
		// if (game->map[step_y + 1][step_x] == MAP_COLLECT)
		// 	ft_printf("Collect");
		// else if (game->map[step_y + 1][step_x] == MAP_EXIT)
		// 	ft_printf("Exit");
		PLAYER_Y += TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_left(t_game *game, int step_y, int step_x)
{
	if (game->map[step_y][step_x - 1] != MAP_WALL)
	{
		// if (game->map[step_y][step_x - 1] == MAP_COLLECT)
			// collect function?
		// else if (game->map[step_y][step_x - 1] == MAP_EXIT)
			// check exit status function
		PLAYER_X -= TILE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	move_right(t_game *game)
{
	if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE + 1] != MAP_WALL)
	{
		PLAYER_X += TILE;
		game->move_count++;
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_COLLECT)
			collect_found(game);
		if (game->map[PLAYER_Y / TILE][PLAYER_X / TILE] == MAP_EXIT)
			exit_found(game);
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	int	step_y;
	int	step_x;

	game = param;
	step_y = PLAYER_Y / TILE;
	step_x = PLAYER_X / TILE;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{	
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			move_up(game, step_y, step_x);
		else if (keydata.key == MLX_KEY_DOWN)
			move_down(game, step_y, step_x);
		else if (keydata.key == MLX_KEY_LEFT)
			move_left(game, step_y, step_x);
		else if (keydata.key == MLX_KEY_RIGHT)
			move_right(game);
	}
}
