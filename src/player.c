/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:48 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/07 16:10:49 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void update_player(t_data *data, int px, int py)
{
	data->player_position->x += px;
	data->player_position->y += py;

    if (data->map == NULL)
    {
        write(1, "Error: dat->map is NULL in deal_key", 100);
        return ;
    }  
    ft_draw_map(data->map);
}

int	deal_key(int key, t_data *data)
{


    data->player_position = ft_find_player(data->map);
    if (data->player_position == NULL)
    {
        write(1, "Error: dat->player_pos is NULL in deal_key", 100);
        return (1);
    }
    if (data->player_position != NULL)
    {
	    if (key == 53)
		    exit(0);
        else if (key == 126) // Arrow key up
            update_player(data, 0, -1);
        else if (key == 125) // Arrow key down
            update_player(data, 0, 1);
        else if (key == 123) // Arrow key left
            update_player(data, -1, 0);
        else if (key == 124) // Arrow key right
            update_player(data, 1, 0);
    }
    // Redraw the player at the updated position
    // mlx_clear_window(mlx, win);
    // mlx_pixel_put(mlx, win, player.x, player.y, 0xFFFFFF);

    return 0;
}
