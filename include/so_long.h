/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:53:46 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/23 17:53:46 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "fcntl.h"
# include <stdio.h>
# include <mlx.h>
# include <mlx_int.h>

# define TRUE 1
# define FALSE 0
# define START 0

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define M_MALLOC_ERROR "Error\n: malloc error.\n"
# define M_OPEN_FILE_E "Error\n: can't open image file.\n"
# define M_CLOSE_WIN "Closing the window and quitting the program.\n"

# define ME_NOT_FREE -1
# define ME_MODE_MLX 0
# define ME_MODE_ASSETS 1
# define ME_MODE_S_MAP 2
# define ME_MODE_MAP 3
# define ME_MODE_STRS 4

# define IMG_H 120
# define IMG_W 120

# define PART_WALL "textures/wall.xpm"
# define PART_PLAYER "textures/player.xpm"
# define PART_C "textures/fish.xpm"
# define PART_EXIT "textures/exit.xpm"
# define PART_BG "textures/bg.xpm"

typedef struct s_c_fill
{
	size_t	count_e;
	size_t	count_c;
	size_t	count_p;
}	t_c_fill;

typedef struct s_map
{
	char	**strs;
	size_t	count_e;
	size_t	count_c;
	size_t	count_p;
	int		height;
	int		width;
}	t_map;

// Player position
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_assets
{
	t_img	*img_p;
	t_img	*img_w;
	t_img	*img_c;
	t_img	*img_bg;
	t_img	*img_exit;
}	t_assets;

typedef struct s_map_status
{
	t_pos	player_pos;
	t_map	*map;
	size_t	walk_count;
	t_pos	exit_pos;
	int		is_win;
}	t_map_status;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	t_map_status	*map;
	t_assets		*assets;
}	t_mlx;

// map validate and init
t_map			*map_init(int argc, char const *argv[]);
void			map_validate(t_map *map);
int				check_flood_fill(t_map map);
void			count_obj_in_map(t_map *map);
t_pos			find_pos(char **strs, char find);

// game start
t_mlx			*start(int argc, char const *argv[]);

// free function
void			free_map_status(t_map_status *data);
void			free_map(t_map *data);
void			free_assets(t_mlx *mlx);
void			free_mlx(t_mlx *data);

// malloc error
void			print_error(void *data, int mode, char *message);

// draw
void			draw_map(t_mlx *game);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

#endif
