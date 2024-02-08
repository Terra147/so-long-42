/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:28:27 by awadeng           #+#    #+#             */
/*   Updated: 2024/02/08 12:15:32 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_mlx *mlx, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(mlx->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_mlx *game)
{
	int		y;
	int		x;
	char	**map;

	map = game->map->map->strs;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw(game, game->assets->img_bg, x * IMG_W, y * IMG_H);
			if (map[y][x] == '1')
				draw(game, game->assets->img_w, x * IMG_W, y * IMG_H);
			else if (map[y][x] == 'C')
				draw(game, game->assets->img_c, x * IMG_W, y * IMG_H);
			x++;
		}
		y++;
	}
	draw(game, game->assets->img_exit,
		game->map->exit_pos.x * IMG_W, game->map->exit_pos.y * IMG_H);
	draw(game, game->assets->img_p,
		game->map->player_pos.x * IMG_W, game->map->player_pos.y * IMG_H);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}
