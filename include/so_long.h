/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:47:16 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/22 16:13:34 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define COLLECTIBLE_PATH "./assets/carrotsprite1.xpm"
# define BACKGROUND_PATH "./assets/background.xpm"
# define WALL_PATH "./assets/blackwall.xpm"
# define EXIT_PATH "./assets/exit.xpm"
# define HERO_PATH "./assets/hero.xpm"
# define MONSTER_PATH "./assets/monster.xpm"
# define WIN_PATH "./assets/win.xpm"

typedef struct s_position
{
	size_t		x;
	size_t		y;
}				t_position;

typedef struct s_map
{
	size_t		h;
	size_t		w;
	char		**tab;
	t_position	*exit;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_asset
{
	t_img		*collectible;
	t_img		*hero;
	t_img		*exit;
	t_img		*background;
	t_img		*wall;
	t_img		*win;
	t_img		*monster;
}				t_asset;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			moves;
	t_img		*img;
	t_asset		*asset;
	t_position	*player_position;
	t_map		*map;
}				t_data;

// control 1 & parsing
int				ft_first_control(int ac, char *av);
int				ft_strscmp(char *s1, char *s2);
int				ft_control_extension(char *str);
int				ft_control(t_data *data);
int				ft_control_square(t_map *map);

// control 2 floodfill
char			**ft_copy_map(t_map *map, t_data *data);
char			**flood_fill(int x, int y, char **copy);
int				ft_find_exit(t_data *data);
int				control_fill_final(char **map, int size, t_data *data);
int				valid_path(t_data *data);

// control 3
int				ft_control_wall(t_map *map);
int				ft_is_map_symb(char c);
int				ft_count_symb(t_map *map, char s);
int				ft_control_symb(t_map *map);
int				ft_check_asset(void);

// game_utils
void			check_if_ennemies(t_data *data);
int				count_collectible(t_data *data);
void			update_exit(t_data *data);
int				ft_launch_game(t_data *data);

// map utils
int				ft_calculate_size_map(char **av);
t_map			*ft_create_map(char **av, int size, t_data *data);
void			update_map(t_data *data);
void			ft_draw_map(t_data *data);

// image utils
t_img			*load_image(t_data *data, char *xpm_path);
void			draw_image(t_img *img, t_data *data, int x, int y);
int				define_image(t_data *data);

// player
void			print_moves(t_data *data);
void			ft_find_player(t_data *data);
void			update_player(t_data *data, int px, int py);
int				check_final(t_data *data);

// player2
int				move_player(int key, t_data *data);
int				deal_key(int key, t_data *data);

// free functions
void			free_asset(void *mlx_ptr, t_img *asset);
void			free_assets(t_data *data);
void			free_player(t_data *data);
void			free_map(t_data *data);
void			ft_free_control(t_data *data);

// free_functions2
int				on_destroy(t_data *data);

// mallocfunction
void			initialize_data(t_data *data, int size);
void			exit_error(t_data *data, char *err_msg);

#endif