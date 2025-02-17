#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512
#define CUBE_SIZE 100
#define BACKGROUND_COLOR 0xADD8E6FF
#define CUBE_COLOR 0xFF69B4FF

static mlx_image_t* image;
static mlx_image_t* background;

void ft_background(void)
{
	uint32_t	i = 0;
	uint32_t	y = 0;

	while (i < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(background, i, y, BACKGROUND_COLOR);
			y++;
		}
		i++;
	}
}

void ft_cube(void)
{
	uint32_t	i = 0;
	uint32_t	y = 0;

	while (i < CUBE_SIZE)
	{
		y = 0;
		while (y < CUBE_SIZE)
		{
			mlx_put_pixel(image, i, y, CUBE_COLOR);
			y++;
		}
		i++;
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(background = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, CUBE_SIZE, CUBE_SIZE)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	ft_background();
	ft_cube();

	mlx_image_to_window(mlx, background, 0, 0);
	mlx_image_to_window(mlx, image, 0, 0);
	
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);

	mlx_terminate(mlx);
	
	return (EXIT_SUCCESS);
}