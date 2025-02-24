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


// void	draw_floor(t_game *game, t_images *image)


// void	draw_map(t_game *game, t_images *image)