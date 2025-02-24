#include "so_long.h"

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (game->map_width / 32))
	{
		y = 0;
		while (y < (game->map_heigth / 32))
		{
			mlx_image_to_window(game->mlx, game->img->floor, x * 32, y * 32);
			y++;
		}
		x++;
	}
}

void ft_player(t_game *game)
{
	mlx_image_to_window(game->mlx, game->img->player, 0, 0);
}