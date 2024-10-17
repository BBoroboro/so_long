/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:28:56 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 15:55:48 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_control_wall(t_map *map)
{
	size_t	x;
	size_t	y;

	x = -1;
	y = -1;
	while (++x < map->w - 1)
		if (map->tab[0][x] != '1')
			return (1);
	while (++y < map->h - 1)
		if (map->tab[y][x] != '1')
			return (1);
	while (x > 0)
		if (map->tab[y][x--] != '1')
			return (1);
	while (y > 0)
		if (map->tab[y--][x] != '1')
			return (1);
	return (0);
}

int	ft_is_map_symb(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || c == 'M')
		return (0);
	return (1);
}

int	ft_count_symb(t_map *map, char s)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map->tab[y])
	{
		x = 0;
		while (map->tab[y][x] != '\0')
		{
			if (map->tab[y][x] == s)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	ft_control_symb(t_map *map)
{
	int	x;
	int	y;

	if (ft_count_symb(map, 'E') != 1)
		return (1);
	if (ft_count_symb(map, 'P') != 1)
		return (1);
	if (ft_count_symb(map, 'C') < 1)
		return (1);
	y = 0;
	while (map->tab[y])
	{
		x = 0;
		while (map->tab[y][x] != '\0')
		{
			if (ft_is_map_symb(map->tab[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_asset(void)
{
	if (open(COLLECTIBLE_PATH, O_RDONLY) == -1 || open(BACKGROUND_PATH,
			O_RDONLY) == -1 || open(WALL_PATH, O_RDONLY) == -1
		|| open(EXIT_PATH, O_RDONLY) == -1 || open(HERO_PATH, O_RDONLY) == -1
		|| open(MONSTER_PATH, O_RDONLY) == -1 || open(WIN_PATH, O_RDONLY) == -1)
		return (1);
	return (0);
}
