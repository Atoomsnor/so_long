#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_textures));
	game->txt->floor = mlx_load_png("./images/background128.png");
	game->txt->wall = mlx_load_png("./images/wall128.png");
	game->txt->player = mlx_load_png("./images/mouse128.png");
	game->txt->collect = mlx_load_png("./images/cheese128.png");
	game->txt->exit = mlx_load_png("./images/exit128.png");
	game->txt->open = mlx_load_png("./images/open128.png");
	game->txt->enemy = mlx_load_png("./images/spook128.png");
}

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->floor = mlx_texture_to_image(game->mlx, game->txt->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->player = mlx_texture_to_image(game->mlx, game->txt->player);
	game->img->collect = mlx_texture_to_image(game->mlx, game->txt->collect);
	game->img->exit = mlx_texture_to_image(game->mlx, game->txt->exit);
	game->img->open = mlx_texture_to_image(game->mlx, game->txt->open);
	game->img->enemy = mlx_texture_to_image(game->mlx, game->txt->enemy);
	mlx_delete_texture(game->txt->floor);
	mlx_delete_texture(game->txt->wall);
	mlx_delete_texture(game->txt->player);
	mlx_delete_texture(game->txt->collect);
	mlx_delete_texture(game->txt->exit);
	mlx_delete_texture(game->txt->open);
	mlx_delete_texture(game->txt->enemy);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->floor, x * 128, y * 128);	
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, game->img->wall, x * 128, y * 128);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, game->img->open, x * 128, y * 128);
				mlx_image_to_window(game->mlx, game->img->exit, x * 128, y * 128);
			}
			x++;
		}
		y++;
	}
}

void draw_conditions(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MAP_PLAYER)
				mlx_image_to_window(game->mlx, game->img->player, x * 128, y * 128);
			if (game->map[y][x] == MAP_COLLECT)
				mlx_image_to_window(game->mlx, game->img->collect, x * 128, y * 128);
			x++;
		}
		y++;
	}
}