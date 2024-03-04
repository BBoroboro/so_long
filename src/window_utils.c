/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:25 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/04 13:33:27 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx/mlx.h>

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	ft_create_window(void)
{
	t_data data;
	//t_data img;

	data.mlx_ptr = mlx_init();
	if(!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Hi frero !");
	if(!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	t_img	*my_image;

	my_image = load_image(data.mlx_ptr, "./assets/rock_ice_alt_tileset_1.xpm");
	if (!my_image)
		return(free(data.mlx_ptr), 1);

    draw_image(my_image, data.mlx_ptr, data.win_ptr, 0, 0);

	mlx_loop(data.mlx_ptr);
	//free(data.mlx_ptr); might lead to mem leaks The mlx_loop function does not return until the window is closed, so the free(data.mlx_ptr) statement after the loop will not be executed. Instead, you should free the resources after the loop or use mlx_loop_hook to set up a callback that can handle cleanup before exiting the loop.
	return (0);
}