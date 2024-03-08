/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:44:19 by mamoulin          #+#    #+#             */
/*   Updated: 2024/02/28 16:44:21 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx/mlx.h>


int	ft_calculate_size_map(char **av)
{
	int map_fd;
	int	i;
	int	j;
	char *line;

	i = 0;
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1) // this should be enough to check if its a file or directory
	{
		printf("can't open the map\n");
		return (1);
	}
	line = get_next_line(map_fd);
	j = ft_strlen(line);
	while(line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(map_fd);
	}
	close (map_fd);
	return (i);
}

t_map	*ft_create_map(char **av, int size)
{
	t_map *map;
	int	map_fd;
	char *line;
	int	i;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		printf("Memory allocation error\n");
		return NULL;
	}
	map->tab = malloc(sizeof(char *) * (size + 1));
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
	{
		printf("can't open the map\n");
		return NULL;
	}
	line = get_next_line(map_fd);
	i = 0;
	map->h = size;
	map->w = strlen(line);
	while (line != NULL)
	{
		map->tab[i] = ft_strdup(line);
		if(!map->tab[i])
		{
			printf("c est de la merde\n");
			return NULL;
		}
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	map->tab[i] = NULL;
	close(map_fd);
	return (map);
}


void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	// if (x >= 0 && y >= 0 && x < data->width && y < data->heigth) //use img.h if you creat a struct img
	// {
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	//}
}



// PROTECT FIRST OPEN IN CASE THE MAP DOESNT EXIST !!!
int	main(int ac, char **av)
{
	t_map *map;
	int	i;

	map = NULL;
	if (ac != 2)
	{
		printf("error: incorrect number of args\n");
		return (1);
	}
	if (ft_strscmp(".ber", av[1]) != 0 || ft_control_extension(av[1])) // also chesk if it is file or dir
	{
		printf("Error different map extension\n");
		return (0);
	}
	else
		printf("la map est bonne\n");

	i = ft_calculate_size_map(av);
	map = ft_create_map(av, i);



	i = 0;
	printf("%zu is my map height\n", map->h);
	printf("%zu is my map width\n", map->w);
	while(map->tab[i])
	{
		printf("%s", map->tab[i]);
		i++;
	}
	if (ft_control_size(map) == 0)
		printf("My map is square\n");
	else
		printf("the map isn't square\n");
	if (ft_control_wall(map) == 0)
		printf("Ext walls are ok\n");
	else
		printf("Ext walls are not ok\n");
	if (ft_control_symb(map) == 0)
		printf("symbols are ok\n");
	else
		printf("symbols are not ok\n");
	valid_path(map);


	ft_draw_map(map);
	
	

	ft_free_tab(map->tab);
	free(map); // utile?
	return(0);
}