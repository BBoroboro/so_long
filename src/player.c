/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:48 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/23 14:25:02 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *data)
{
	char	*number;

	ft_printf("You made %d moves!\n", data->moves);
	number = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 16, 16, 16711680, number);
	free(number);
	data->moves += 1;
}

void	ft_find_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->tab[y])
	{
		x = 0;
		while (data->map->tab[y] && data->map->tab[y][x] != '\0')
		{
			if ((data->map->tab[y][x]) == 'P')
			{
				data->player_position->x = x;
				data->player_position->y = y;
			}
			x++;
		}
		y++;
	}
}

void	update_player(t_data *data, int px, int py)
{
	data->player_position->x += px;
	data->player_position->y += py;
	check_if_ennemies(data);
	if (data->map == NULL)
		return ;
	update_map(data);
	ft_draw_map(data);
	print_moves(data);
}

int	check_final(t_data *data)
{
	size_t	x;
	size_t	y;
	int		count;

	count = 0;
	y = 0;
	while (data->map->tab[y])
	{
		x = 0;
		while (data->map->tab[y][x])
		{
			if (data->map->tab[y][x] == 'C' || data->map->tab[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count > 0)
		return (1);
	return (0);
}
