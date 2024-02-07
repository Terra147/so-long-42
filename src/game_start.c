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
	t_map	*map;
	t_map_status	*map_status;

	map = map_init(argc, argv);
	map_status = malloc(sizeof(t_map_status));
	if (!map_status)
		malloc_error(map, ME_MODE_MAP);
	map_status->map = map;
	map_status->player_pos = find_pos(map->strs, PLAYER);
	map_status->exit_pos = find_pos(map->strs, EXIT);
	map_status->get_c = START;
	map_status->walk_count = START;
	return (map_status);
}

static t_img	*load_img(t_mlx *game, char *part)
{
	int	width;
	int	height;
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		malloc_error(game, ME_MODE_MLX);
	img = mlx_xpm_file_to_image(game->mlx, part, &width, &height);
	if (!(img))
	{
		ft_putstr_fd("ERROR\n: can't open image file.\n", 2);
		free_mlx(game);
		free(img);
		exit(1);
	}
	img->height = height;
	img->width = width;
	return (img);
}

static void	load_assets(t_mlx *game)
{
	t_assets	*assets;

	assets = ft_calloc(sizeof(t_assets), 1);
	if (!assets)
		malloc_error(game, ME_MODE_MLX);
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

	game = malloc(sizeof(t_mlx));
	game->assets = NULL;
	if (!game)
		malloc_error(map_status, ME_MODE_S_MAP);
	game->mlx = mlx_init();
	if (!(game->mlx))
	{
		free(game);
		malloc_error(map_status, ME_MODE_S_MAP);
	}
	game->mlx_win = mlx_new_window(game->mlx, IMG_WIDTH * map_status->map->width, IMG_HEIGHT * map_status->map->height, "so_long");
	if (!(game->mlx_win))
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
		malloc_error(map_status, ME_MODE_S_MAP);
	}
	game->mlx_img = mlx_new_image(game->mlx, map_status->map->width * IMG_WIDTH, map_status->map->height * IMG_HEIGHT);
	if (!(game->mlx_img))
		malloc_error(map_status, ME_MODE_MLX);
	game->map = map_status;
	load_assets(game);
	return (game);
}

t_mlx	*start(int argc, char const *argv[])
{
	t_map_status	*map_status;
	t_assets		*assets;

	map_status = set_map(argc, argv);
	return (mlx_start(map_status));
}
