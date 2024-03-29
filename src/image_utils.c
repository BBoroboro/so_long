/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:33:33 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/04 13:33:34 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_img	*load_image(void *mlx_ptr, char *xpm_path)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, xpm_path, &(img->width), &(img->height));
	if (!img->img_ptr)
	{
		free(img);
		return (NULL);
	}
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

void	draw_image(t_img *img, void *mlx_ptr, void *win_ptr, int x, int y)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img_ptr, x, y);
}

// t_img	*define_image(t_img *img, void *data)
// {
// 	img->textures[0] = load_image(data.mlx_ptr, "./assets/blackwall.xpm");
// 	if (!img->textures[0])
// 		return(free(data.mlx_ptr), NULL);
// 	img->textures[1] = load_image(data.mlx_ptr, "./assets/sky.xpm");
// 	if (!img->textures[1])
// 		return(free(data.mlx_ptr), NULL);
// 	return (img);
// }