#include "so_long.h"
#include <stdio.h>

int	check_rectangle(char **map)
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
