/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:48:08 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/23 13:52:30 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_control_size(t_data *data, size_t y, size_t x)
{
	if (x > 70 || y > 30)
	{
		ft_printf("Error: the map is too big\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
}

int	ft_calculate_size_map(char **av)
{
	int		map_fd;
	int		i;
	char	*line;

	i = 0;
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
	{
		ft_printf("Error : Can't open the map\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(map_fd);
	if (line == NULL)
	{
		ft_printf("Error : Nothing to read\n");
		exit(EXIT_FAILURE);
	}
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(map_fd);
	}
	return (close(map_fd), i);
}

t_map	*ft_create_map(char **av, int size, t_data *data)
{
	int		map_fd;
	char	*line;
	int		i;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
		return (NULL);
	line = get_next_line(map_fd);
	i = 0;
	data->map->h = size;
	data->map->w = strlen(line) - 1;
	while (line != NULL)
	{
		ft_strlcpy(line, line, ft_strlen(line));
		data->map->tab[i] = ft_strdup(line);
		if (!data->map->tab[i])
			return (ft_free_tab(data->map->tab), NULL);
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	ft_control_size(data, data->map->h, data->map->w);
	data->map->tab[i] = NULL;
	close(map_fd);
	return (data->map);
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map->tab[++y])
	{
		x = -1;
		while (data->map->tab[y][++x])
		{
			if (data->map->tab[y][x] == '1')
				draw_image(data->asset->wall, data, x * 32, y * 32);
			else if (data->map->tab[y][x] == '0')
				draw_image(data->asset->background, data, x * 32, y * 32);
			else if (data->map->tab[y][x] == 'C')
				draw_image(data->asset->collectible, data, x * 32, y * 32);
			else if (data->map->tab[y][x] == 'P')
				draw_image(data->asset->hero, data, data->player_position->x
					* 32, data->player_position->y * 32);
			else if (data->map->tab[y][x] == 'E')
				draw_image(data->asset->exit, data, x * 32, y * 32);
			else if (data->map->tab[y][x] == 'M')
				draw_image(data->asset->monster, data, x * 32, y * 32);
		}
	}
}

void	update_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map->tab[y])
	{
		x = 0;
		while (data->map->tab[y][x])
		{
			if (data->map->tab[y][x] == 'P')
				data->map->tab[y][x] = '0';
			x++;
		}
		y++;
	}
	x = data->player_position->x;
	y = data->player_position->y;
	data->map->tab[y][x] = 'P';
}
