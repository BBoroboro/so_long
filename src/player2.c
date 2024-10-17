/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:53 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 18:05:23 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->player_position->x;
	y = data->player_position->y;
	if (key == XK_Escape)
		return (on_destroy(data), 1);
	if (data->player_position != NULL)
	{
		if (key == XK_w && data->map->tab[y - 1][x] != '1'
			&& data->map->tab[y - 1][x] != 'E')
			update_player(data, 0, -1);
		else if (key == XK_s && data->map->tab[y + 1][x] != '1'
			&& data->map->tab[y + 1][x] != 'E')
			update_player(data, 0, 1);
		else if (key == XK_a && data->map->tab[y][x - 1] != '1'
			&& data->map->tab[y][x - 1] != 'E')
			update_player(data, -1, 0);
		else if (key == XK_d && data->map->tab[y][x + 1] != '1'
			&& data->map->tab[y][x + 1] != 'E')
			update_player(data, 1, 0);
	}
	return (0);
}

int	deal_key(int key, t_data *data)
{
	move_player(key, data);
	if (count_collectible(data) == 0)
		update_exit(data);
	if (check_final(data) == 0)
	{
		ft_printf("YOU MADE IT WITH %d MOVES!\n", data->moves);
		draw_image(data->asset->win, data, 0, 0);
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
