/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:14:50 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 23:48:22 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <sys/time.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
// Keycode definitions for AWDS keys

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307


// void    print_strs(t_map_status *map)
// {
//     int i;

//     i = 0;
//     ft_printf("===== MAP =====\n");
//     while (map->map->strs[i])
//     {
//         ft_printf("%s\n", map->map->strs[i]);
//         i++;
//     }
//     ft_printf("Exit : x = %d, y = %d\n", map->exit_pos.x, map->exit_pos.y);
//     ft_printf("\n");
// }

int is_move_to(t_map_status *map, int to_x, int to_y)
{
	if (map->map->strs[to_y][to_x] == '1')
		return (0);
	map->map->strs[map->player_pos.y][map->player_pos.x] = '0';
	map->map->strs[to_y][to_x] = 'P';
	map->player_pos = find_pos(map->map->strs, 'P');
	return (1);
}

static void update_win(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	ft_printf("%d\n", ++(data->map->walk_count));
}

int key_move(int keycode, t_mlx *data)
{
	if (keycode == KEY_ESC)
	{
		free_mlx(data);
		exit(0);
	}
	else if (keycode == KEY_A)
	{
		if (is_move_to(data->map, data->map->player_pos.x - 1, data->map->player_pos.y))
			update_win(data);
	}
	else if (keycode == KEY_W)
	{
		if (is_move_to(data->map, data->map->player_pos.x, data->map->player_pos.y - 1))
			update_win(data);
	}
	else if (keycode == KEY_D)
	{
		if (is_move_to(data->map, data->map->player_pos.x + 1, data->map->player_pos.y))
			update_win(data);
	}
	else if (keycode == KEY_S)
	{
		if (is_move_to(data->map, data->map->player_pos.x, data->map->player_pos.y + 1))
			update_win(data);
	}
}

int main(int argc, char const *argv[])
{
	t_mlx	*game;

	game = start(argc, argv);
	ft_printf("Ready\n");
	ft_printf("H = %d, W = %d\n", game->assets->img_w->height, game->assets->img_w->width);
	draw_map(game);
	mlx_key_hook(game->mlx_win, key_move, game);
	mlx_loop(game->mlx);
	return (0);
}
