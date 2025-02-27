#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_PLAYER 'P'
# define MAP_COLLECT 'C'
# define MAP_EXIT 'E'
# define TILE 128
// # define MAP_ENEMY 'x'

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
	mlx_texture_t	*open;
	mlx_texture_t	*enemy;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*collect;
	mlx_image_t		*exit;
	mlx_image_t		*open;
	mlx_image_t		*enemy;
}	t_images;

typedef struct s_game
{
	struct s_textures	*txt;
	struct s_images		*img;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_heigth;
	int					move_count;
	int					collec_count;
}	t_game;

int		check_rectangle(char **map);

void	map_size(t_game *game, char **map);
void	free_map(char **map);
char	**read_map(char *argv_map);

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game);
void	draw_conditions(t_game *game);
// void	ft_test(t_game *game);
// void	ft_player(t_game *game);

void	ft_key_hook(mlx_key_data_t keydata, void* param);

#endif