
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 320
#define HEIGHT 320

static t_textures textures;
static t_images images;

void get_textures_and_images(mlx_t* mlx)
{
	textures.floor = mlx_load_png("./images/floor.png");
	textures.player = mlx_load_png("./images/spook32.png");
	images.floor = mlx_texture_to_image(mlx, textures.floor);
	images.player = mlx_texture_to_image(mlx, textures.player);
	mlx_delete_texture(textures.floor);
	mlx_delete_texture(textures.player);
}

void ft_background(mlx_t* mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < (WIDTH / 32))
	{
		y = 0;
		while (y < (HEIGHT / 32))
		{
			mlx_image_to_window(mlx, images.floor, x * 32, y * 32);
			y++;
		}
		x++;
	}
}

void ft_player(mlx_t* mlx)
{
	mlx_image_to_window(mlx, images.player, 0, 0);
}

void ft_key_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t* mlx = param;

	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{	
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(mlx);
		else if (keydata.key == MLX_KEY_UP)
			images.player->instances[0].y -= 32;
		else if (keydata.key == MLX_KEY_DOWN)
			images.player->instances[0].y += 32;
		else if (keydata.key == MLX_KEY_LEFT)
			images.player->instances[0].x -= 32;
		else if (keydata.key == MLX_KEY_RIGHT)
			images.player->instances[0].x += 32;
	}
}

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	get_textures_and_images(mlx);
	
	ft_background(mlx);
	ft_player(mlx);
	
	mlx_key_hook(mlx, ft_key_hook, mlx);

	mlx_loop(mlx);

	mlx_terminate(mlx);
	
	return (EXIT_SUCCESS);
}
