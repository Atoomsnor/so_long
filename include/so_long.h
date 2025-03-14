/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:23:14 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 16:40:51 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define TRUE 0
# define FALSE 1
# define TILE 128

# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_PLAYER 'P'
# define MAP_COLLECT 'C'
# define MAP_EXIT 'E'

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
	char				**tempmap;
	size_t				map_width;
	int					map_heigth;
	int					move_count;
	int					collect_count;
	int					collect_amount;
}	t_game;

int		check_extension(char *argv_map);
void	free_map(char **map);
void	map_size(t_game *game, char **map);

char	**get_map(char *argv);
char	**get_lines(char *argv, int *lines);

int		check_empty(char **map);
int		check_rectangle(char **map);
int		check_characters(char **map, int exit, int player, int collect);
int		check_walls(char **map);
int		check_map(char **map);

int		flood_player(char **map, int pos_y, int pos_x);
void	flood_map(t_game *game, int pos_y, int pos_x);
int		flood_check(char **tempmap);
int		flood_solve(t_game *game, char *argv);

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	get_scale(t_game *game);
void	put_map(t_game *game);
void	put_objects(t_game *game);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_key_hook(mlx_key_data_t keydata, void *param);

void	found_collect(t_game *game);
void	found_exit(t_game *game);

#endif