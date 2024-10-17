/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:44:19 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 14:31:41 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	t_data	data;
	int		size_map;

	ft_memset(&data, 0, sizeof(t_data));
	if (ft_first_control(ac, av[1]) == 1)
		return (1);
	size_map = ft_calculate_size_map(av);
	initialize_data(&data, size_map);
	data.map = ft_create_map(av, size_map, &data);
	if (ft_control(&data) == 1 || valid_path(&data) == 1)
		exit_error(&data, "Error: map invalid\n");
	ft_launch_game(&data);
	return (0);
}
