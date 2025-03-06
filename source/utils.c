/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roversch <roversch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:00:01 by roversch          #+#    #+#             */
/*   Updated: 2025/03/06 15:14:12 by roversch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len - 3] == 'b'
		&& argv[len - 2] == 'e' && argv[len - 1] == 'r')
		return (TRUE);
	return (FALSE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	map_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(map[0]) * TILE - TILE;
	while (map[i])
		i++;
	game->map_heigth = i * TILE;
}
