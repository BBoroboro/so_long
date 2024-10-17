/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:56:58 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 17:10:27 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

char	**ft_copy_map(t_map *map, t_data *data)
{
	size_t	i;
	char	**copy;
	size_t	tab_size;

	tab_size = map->h;
	i = 0;
	copy = malloc(sizeof(char *) * (tab_size + 1));
	if (!copy)
		exit_error(data, "Error: Malloc\n");
	while (i < tab_size)
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

char	**flood_fill(int x, int y, char **copy)
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

int	ft_find_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->map->exit = malloc(sizeof(t_position));
	if (!data->map->exit)
		return (ft_printf("Error: malloc\n"), 1);
	while (data->map->tab[y])
	{
		x = 0;
		while (data->map->tab[y] && data->map->tab[y][x] != '\0')
		{
			if ((data->map->tab[y][x]) == 'E')
			{
				data->map->exit->x = x;
				data->map->exit->y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	control_fill_final(char **map, int size, t_data *data)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	ft_find_exit(data);
	x = data->map->exit->x;
	y = data->map->exit->y;
	free(data->map->exit);
	if (c == 0 && (map[y][x - 1] == 'F' || map[y][x + 1] == 'F'
			|| map[y - 1][x] == 'F' || map[y + 1][x] == 'F'))
		return (0);
	return (ft_printf("Error: there is no path to victory!\n"), 1);
}

int	valid_path(t_data *data)
{
	char	**copy;
	int		x;
	int		y;

	ft_find_player(data);
	copy = ft_copy_map(data->map, data);
	if (!copy)
		exit_error(data, "Error: Malloc\n");
	x = data->player_position->x;
	y = data->player_position->y;
	copy = flood_fill(x, y, copy);
	if (control_fill_final(copy, data->map->h, data))
	{
		ft_free_tab(copy);
		return (1);
	}
	ft_free_tab(copy);
	return (0);
}
