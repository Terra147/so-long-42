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

static void	update_win(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	ft_printf("%d\n", ++(data->map->walk_count));
	if (data->map->map->count_c == 0
		&& data->map->player_pos.x == data->map->exit_pos.x
		&& data->map->player_pos.y == data->map->exit_pos.y)
	{
		ft_printf("You Win!!!\n");
		free_mlx(data);
		exit(0);
	}
}

static int	is_move_to(t_mlx *data, int to_x, int to_y)
{
	t_map_status	*map;

	map = data->map;
	if (map->map->strs[to_y][to_x] == '1')
		return (0);
	map->map->strs[map->player_pos.y][map->player_pos.x] = '0';
	map->map->strs[to_y][to_x] = 'P';
	map->player_pos = find_pos(map->map->strs, 'P');
	count_obj_in_map(map->map);
	update_win(data);
	return (1);
}

static int	key_move(int keycode, t_mlx *data)
{
	t_pos	p_pos;

	p_pos = data->map->player_pos;
	if (keycode == KEY_ESC)
	{
		free_mlx(data);
		ft_printf(M_CLOSE_WIN);
		exit(0);
	}
	else if (keycode == KEY_A)
		is_move_to(data, p_pos.x - 1, p_pos.y);
	else if (keycode == KEY_W)
		is_move_to(data, p_pos.x, p_pos.y - 1);
	else if (keycode == KEY_D)
		is_move_to(data, p_pos.x + 1, p_pos.y);
	else if (keycode == KEY_S)
		is_move_to(data, p_pos.x, p_pos.y + 1);
	return (0);
}

static int	close_window(t_mlx *data)
{
	ft_printf(M_CLOSE_WIN);
	free_mlx(data);
	exit(0);
}

int	main(int argc, char const *argv[])
{
	t_mlx	*game;

	game = start(argc, argv);
	ft_printf("Ready\n");
	draw_map(game);
	mlx_key_hook(game->mlx_win, key_move, game);
	mlx_hook(game->mlx_win, DestroyNotify, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
