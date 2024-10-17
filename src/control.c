/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:09:48 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/23 13:45:31 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_control(int ac, char *av)
{
	if (ac != 2)
	{
		ft_printf("Error: incorrect number of arguments\n");
		return (1);
	}
	if (ft_strscmp(".ber", av) != 0)
	{
		ft_printf("Error: different map extension\n");
		return (1);
	}
	if (ft_check_asset() == 1)
	{
		ft_printf("Error: can't access the assets\n");
		return (1);
	}
	return (0);
}

int	ft_strscmp(char *s1, char *s2)
{
	int	start;

	start = ft_strlen(s2) - 4;
	while (start--)
		s2++;
	if (*s1 != *s2)
		return (-1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_control(t_data *data)
{
	if (ft_control_square(data->map) == 1)
	{
		ft_printf("Error: the map isn't square!\n");
		return (1);
	}
	if (ft_control_wall(data->map) == 1)
	{
		ft_printf("Error: the external walls are not ok!\n");
		return (1);
	}
	if (ft_control_symb(data->map) == 1)
	{
		ft_printf("Error: the map doesn't have the right symbols\n");
		return (1);
	}
	return (0);
}

int	ft_control_square(t_map *map)
{
	int	i;
	int	height;
	int	width;

	height = map->h;
	width = map->w;
	i = 0;
	while (map->tab[i])
	{
		if (map->w != ft_strlen(map->tab[i]))
			return (1);
		i++;
	}
	return (0);
}
