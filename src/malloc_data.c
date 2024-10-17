/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:46:59 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 14:11:19 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	exit_error(t_data *data, char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	on_destroy(data);
	exit(EXIT_FAILURE);
}

void	initialize_data(t_data *data, int size)
{
	data->map = ft_calloc(1, sizeof(t_map));
	if (data->map == NULL)
		exit_error(data, "Error: Malloc\n");
	data->map->tab = ft_calloc((size + 1), sizeof(char *));
	if (!data->map->tab)
		exit_error(data, "Error: Malloc\n");
	data->player_position = ft_calloc(1, sizeof(t_position));
	if (!data->player_position)
		exit_error(data, "Error: Malloc\n");
	data->asset = ft_calloc(1, sizeof(t_asset));
	if (!data->asset)
		exit_error(data, "Error: Malloc\n");
	data->moves = 1;
}
