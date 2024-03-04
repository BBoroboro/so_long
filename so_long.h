/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:47:16 by mamoulin          #+#    #+#             */
/*   Updated: 2024/02/28 16:47:18 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_position;

typedef struct s_map
{
	size_t	h;
	size_t	w;
	char	**tab;
	t_position *exit;
	t_position *player;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}		t_img;
// differencitate strut data and struct img
// typedef struct s_img //these ones could go to the struct img
// {
// 	t_win	win;
// 	void	*img_ptr;
// 	char	*addr;
// 	int		h;
// 	int		w;
// 	int		bpp;
// 	int		endian;
// 	int		line_len;
// }	t_img;

// typedef struct s_win // and this couldbe a struct window
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		heigth;
// 	int		width;
// }	t_win;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	void	*textures[5];
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
	t_map	*map;
}	t_data;


//control 1 & parsing
int	ft_strscmp(char *s1, char *s2);
int	ft_control_extension(char *str);
int	ft_control_size(t_map *map);
int	ft_control_wall(t_map *map);
int ft_is_map_symb(char c);
int ft_control_symb(t_map *map);

//control 2 floodfill
t_position	*ft_find_player(t_map *map);
char	**ft_copy_map(t_map *map);
char **flood_fill(int x, int y, char **copy);
int control_fill_final(char **map, int size);
int	valid_path(t_map *map);

// window_utils
int on_destroy(t_data *data);
int on_keypress(int keysym, t_data *data);
int	ft_create_window(void);

// image utils
t_img	*load_image(void *mlx_ptr, char *xpm_path);
void	draw_image(t_img *img, void *mlx_ptr, void *win_ptr, int x, int y);


#endif