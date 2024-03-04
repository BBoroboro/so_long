/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:56:58 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/01 13:57:01 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_position	*ft_find_player(t_map *map)
{
	int	x;
	int	y;
	t_position *player;

	y = 0;
	player = malloc(sizeof(t_position));
	if (!player)
		{
			return (NULL);
		}
	while(map->tab[y])
	{
		x = 0;
		while(map->tab[y][x] != '\n')
		{
			if ((map->tab[y][x]) == 'P')
			{
				player->x = x;
				player->y = y;
			}
			x++;
		}
		y++;
	}
	return (player);
}

char	**ft_copy_map(t_map *map)
{
	size_t	i;
	char **copy;
	size_t tab_size;

	tab_size = map->h;
	i = 0;
	copy = malloc(sizeof(char *) * (tab_size + 1));
	if (!copy)
		return (NULL);
	while(i < tab_size)
	{
		copy[i] = ft_strdup(map->tab[i]);
		if (!copy)
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char **flood_fill(int x, int y, char **copy)
{
	if (copy[y][x] == '0' || copy[y][x] == 'C' || copy[y][x] == 'P')
		copy[y][x] = 'F';
	if (copy[y][x + 1] == '0' || copy[y][x + 1] == 'C' || copy[y][x + 1] == 'P')
		flood_fill(x + 1, y, copy);
	if (copy[y][x - 1] == '0' || copy[y][x - 1] == 'C' || copy[y][x - 1] == 'P')
		flood_fill(x - 1, y, copy);
	if (copy[y + 1][x] == '0' || copy[y + 1][x] == 'C' || copy[y + 1][x] == 'P')
		flood_fill(x, y + 1, copy);
	if (copy[y - 1][x] == '0' || copy[y - 1][x] == 'C' || copy[y - 1][x] == 'P')
		flood_fill(x, y - 1, copy);
	return (copy);
}
int control_fill_final(char **map, int size) // in this case, i cant pass through the exit before collecting all C
{
	int x;
	int y;
	int c;
	t_position *exit;

	c = 0;
	y = 0;
	if (!map || !map[y])
		return (1);
	exit = malloc(sizeof(t_position));
	if (!exit)
	{
		//free char **map?
		return (1);
	}
	while(y < size)
	{
		x = 0;
		while(map[y][x] != '\n')
		{
			if (map[y][x] == 'C')
				c++;
			if (map[y][x] == 'E')
				{
					exit->x = x;
					exit->y = y;
				}
			x++;
		}
		y++;
	}
	x = exit->x;
	y = exit->y;
	free(exit);
	if (c == 0 && (map[y][x - 1] == 'F' || map[y][x + 1] == 'F' || map[y - 1][x] == 'F' || map[y + 1][x] == 'F'))
		return (0);
	return (1);
}
int	valid_path(t_map *map)
{
	t_position *player;
	char **copy;
	int x;
	int y;	

	//copy = NULL;
	player = ft_find_player(map);
	copy = malloc(sizeof(char *) * (map->h));
	if (!copy)
		return (1);
	copy = ft_copy_map(map);
	x = player->x;
	y = player->y;
	copy = flood_fill(x, y, copy);
	if (!control_fill_final(copy, map->h))
		printf("map valid frero\n");
	else
		printf("map pas valide frerot\n");
	ft_free_tab(copy); // if pb in alloc in copy_map here i free NULL...
	free(player);
	return (1);
}