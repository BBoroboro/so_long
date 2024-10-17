/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:25 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 10:56:33 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

void	check_if_ennemies(t_data *data)
{
	int	x;
	int	y;

	x = data->player_position->x;
	y = data->player_position->y;
	if (data->map->tab[y][x] == 'M')
	{
		ft_printf("YOU LOSE!\n");
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
}

int	count_collectible(t_data *data)
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
			if (data->map->tab[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count > 0)
		return (1);
	return (0);
}

void	update_exit(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map->tab[y])
	{
		x = 0;
		while (data->map->tab[y][x])
		{
			if (data->map->tab[y][x] == 'E')
			{
				data->map->tab[y][x] = 'C';
				draw_image(data->asset->collectible, data, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

int	ft_launch_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error: MLX\n");
		ft_free_tab(data->map->tab);
		free(data->player_position);
		free(data->asset);
		free(data->map);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->w * 32,
			data->map->h * 32, "Hi frero !");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		data);
	if (define_image(data) == 1)
		return (1);
	ft_draw_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
