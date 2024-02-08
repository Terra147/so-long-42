/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:04:05 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 22:34:54 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map_status	*set_map(int argc, char const *argv[])
{
	t_map			*map;
	t_map_status	*map_status;

	map = map_init(argc, argv);
	map_status = malloc(sizeof(t_map_status));
	if (!map_status)
		print_error(map, ME_MODE_MAP, M_MALLOC_ERROR);
	map_status->map = map;
	map_status->player_pos = find_pos(map->strs, PLAYER);
	map_status->exit_pos = find_pos(map->strs, EXIT);
	map_status->walk_count = START;
	map_status->is_win = FALSE;
	return (map_status);
}

static t_img	*load_img(t_mlx *game, char *part)
{
	int		width;
	int		height;
	t_img	*img;

	img = mlx_xpm_file_to_image(game->mlx, part, &width, &height);
	if (!(img))
		print_error(game, ME_MODE_MLX, M_OPEN_FILE_E);
	img->height = height;
	img->width = width;
	return (img);
}

static void	load_assets(t_mlx *game)
{
	t_assets	*assets;

	assets = ft_calloc(sizeof(t_assets), 1);
	if (!assets)
		print_error(game, ME_MODE_MLX, M_MALLOC_ERROR);
	game->assets = assets;
	assets->img_bg = load_img(game, PART_BG);
	assets->img_c = load_img(game, PART_C);
	assets->img_exit = load_img(game, PART_EXIT);
	assets->img_p = load_img(game, PART_PLAYER);
	assets->img_w = load_img(game, PART_WALL);
}

static t_mlx	*mlx_start(t_map_status *map_status)
{
	t_mlx	*game;

	game = ft_calloc(sizeof(t_mlx), 1);
	if (!game)
		print_error(map_status, ME_MODE_S_MAP, M_MALLOC_ERROR);
	game->map = map_status;
	game->mlx = mlx_init();
	if (!(game->mlx))
		print_error(game, ME_MODE_MLX, M_MALLOC_ERROR);
	game->mlx_win = mlx_new_window(game->mlx, IMG_W * map_status->map->width,
			IMG_H * map_status->map->height, "so_long");
	if (!(game->mlx_win))
		print_error(game, ME_MODE_MLX, M_MALLOC_ERROR);
	game->mlx_img = mlx_new_image(game->mlx, map_status->map->width * IMG_W,
			map_status->map->height * IMG_H);
	if (!(game->mlx_img))
		print_error(game, ME_MODE_MLX, M_MALLOC_ERROR);
	load_assets(game);
	return (game);
}

t_mlx	*start(int argc, char const *argv[])
{
	t_map_status	*map_status;

	map_status = set_map(argc, argv);
	return (mlx_start(map_status));
}
