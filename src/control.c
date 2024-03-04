/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:09:48 by mamoulin          #+#    #+#             */
/*   Updated: 2024/02/29 14:10:12 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

//check if the file end with ".ber"
int	ft_strscmp(char *s1, char *s2)
{
	int start;

	start = ft_strlen(s2) - 4;
	while(start--)
		s2++;
	if (*s1 != *s2)
		return (-1);
	while(*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_control_extension(char *str)
{
	char c;
	int	i;

	i = 0;
	c = '.';
	while(*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	if (i > 1)
		return (1);
	return (0);
}

int	ft_control_size(t_map *map) //ok
{
	int	i;
	int	height;
	int	width;

	height = map->h;
	width = map->w;
	i = 0;
	while(map->tab[i])
	{
		if(map->w != ft_strlen(map->tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_control_wall(t_map *map) //ok
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;

	while(x < map->w - 2)
	{
		if (map->tab[0][x] != '1')
			return (1);
		x++;
	}
	while(y < map->h - 1)
	{
		if (map->tab[y][x] != '1')
			return (1);
		y++;
	}
	while (x > 0)
	{
		if (map->tab[y][x] != '1')
			return (1);
		x--;
	}
	while(y > 0)
	{
		if (map->tab[y][x] != '1')
			return (1);
		y--;;
	}
	return (0);
}

int ft_is_map_symb(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || c == '\n')
		return (0);
	return (1);
}

int ft_control_symb(t_map *map)
{
	int x;
	int y;
	int	p;
	int	c;
	int e;

	p = 0;
	c = 0;
	e = 0;
	y = 0;
	while(map->tab[y])
	{
		x = 0;
		while(map->tab[y][x] != '\n')
		{
			if (map->tab[y][x] == 'P')
				p++;
			if (map->tab[y][x] == 'C')
				c++;
			if (map->tab[y][x] == 'E')
				e++;
			if (ft_is_map_symb(map->tab[y][x]))
			{
				printf("symbol error\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	if (e != 1 || p != 1 || c < 2)
	{
		printf("symbol error 2\n");
		return (1);
	}
	return (0);
}

// int ft_control_map_full(t_map *map)
// {}
