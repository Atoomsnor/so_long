#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>


typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*pickup;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*pickup;
	mlx_image_t		*exit;
}	t_images;

typedef struct s_game
{
	struct s_textures	*txt;
	struct s_images		*img;
	mlx_t				*mlx;
	int					map_width;
	int					map_heigth;
}	t_game;


void	get_textures(t_game *game);
void	get_images(t_game *game);

void	draw_floor(t_game *game);
void	ft_player(t_game *game);

void ft_key_hook(mlx_key_data_t keydata, void* param);

#endif