/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:46:56 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 14:23:47 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_asset(void *mlx_ptr, t_img *asset)
{
	if (!asset)
		return ;
	mlx_destroy_image(mlx_ptr, asset->img_ptr);
	free(asset);
}

void	free_assets(t_data *data)
{
	if (!data->asset)
		return ;
	free_asset(data->mlx_ptr, data->asset->collectible);
	free_asset(data->mlx_ptr, data->asset->exit);
	free_asset(data->mlx_ptr, data->asset->hero);
	free_asset(data->mlx_ptr, data->asset->background);
	free_asset(data->mlx_ptr, data->asset->wall);
	free_asset(data->mlx_ptr, data->asset->win);
	free_asset(data->mlx_ptr, data->asset->monster);
}

void	free_player(t_data *data)
{
	if (!data->player_position)
		return ;
	free(data->player_position);
}

void	free_map(t_data *data)
{
	if (!data->map)
		return ;
	ft_free_tab(data->map->tab);
	free(data->map);
}

void	free_data(t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
}
