#include "so_long.h"
#include <stdio.h>

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

// The map must contain 1 exit, at least 1 collectible, and 1 starting position to
// be valid
// • The map must be closed/surrounded by walls. If it’s not, the program must return
// an error.
// • You have to check if there’s a valid path in the map.
// • You must be able to parse any kind of map, as long as it respects the above rules.

// if any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice

int	check_rectangle(char **map) //!doesnt work if theres no empty line under the map
{
	int		i;
	size_t		len;

	i = 1;
	len = ft_strlen(map[0]);
	while(map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (printf("not rectangle\n"), 1);
		else
			i++;
	}
	return (0);
}
