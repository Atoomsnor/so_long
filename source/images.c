#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_textures));
	game->txt->floor = mlx_load_png("./images/floor.png");
	game->txt->player = mlx_load_png("./images/spook32.png");
}

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->floor = mlx_texture_to_image(game->mlx, game->txt->floor);
	game->img->player = mlx_texture_to_image(game->mlx, game->txt->player);
	mlx_delete_texture(game->txt->floor);
	mlx_delete_texture(game->txt->player);
}

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