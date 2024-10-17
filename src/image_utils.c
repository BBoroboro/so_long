/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:33 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 14:07:20 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_img	*load_image(t_data *data, char *xpm_path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_error(data, "Error: Malloc\n");
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, xpm_path, &img->width,
			&img->height);
	if (!img->img_ptr)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_line),
			&(img->endian));
	return (img);
}

void	draw_image(t_img *img, t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_ptr, x, y);
}

int	define_image(t_data *data)
{
	data->asset->collectible = load_image(data, "./assets/carrotsprite1.xpm");
	if (!data->asset->collectible)
		exit_error(data, "Error: image loading\n");
	data->asset->background = load_image(data, "./assets/background.xpm");
	if (!data->asset->background)
		exit_error(data, "Error: image loading\n");
	data->asset->wall = load_image(data, "./assets/blackwall.xpm");
	if (!data->asset->wall)
		exit_error(data, "Error: image loading\n");
	data->asset->exit = load_image(data, "./assets/exit.xpm");
	if (!data->asset->exit)
		exit_error(data, "Error: image loading\n");
	data->asset->hero = load_image(data, "./assets/hero.xpm");
	if (!data->asset->hero)
		exit_error(data, "Error: image loading\n");
	data->asset->win = load_image(data, "./assets/win.xpm");
	if (!data->asset->win)
		exit_error(data, "Error: image loading\n");
	data->asset->monster = load_image(data, "./assets/monster.xpm");
	if (!data->asset->monster)
		exit_error(data, "Error: image loading\n");
	return (0);
}
