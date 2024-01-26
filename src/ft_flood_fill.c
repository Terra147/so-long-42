/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:41:10 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/24 13:41:10 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_strsdup(char **strs)
{
	int		size;
	char	**result;

	if (!strs)
		return (NULL);
	size = 0;
	while (strs[size])
		size++;
	result = malloc(sizeof(char *) * (size + 1));
	size = 0;
	while (strs[size])
	{
		result[size] = ft_strdup(strs[size]);
		size++;
	}
	result[size] = NULL;
	return (result);
}

t_pos	find_pos(t_map map, char find)
{
	t_pos	player_pos;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map.strs[y])
	{
		x = 0;
		while (map.strs[y][x])
		{
			if (map.strs[y][x] == find)
			{
				player_pos.x = x;
				player_pos.y = y;
				return (player_pos);
			}
			x++;
		}
		y++;
	}
	return (player_pos);
}

static void	flood_fill(t_map *map, int x, int y, char to_fill)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->strs[y][x] != WALL && map->strs[y][x] != to_fill)
	{
		if (map->strs[y][x] == EXIT)
			map->count_e = map->count_e + 1;
		if (map->strs[y][x] == COLLECTIBLE)
			map->count_c = map->count_c + 1;
		map->strs[y][x] = to_fill;
		flood_fill(map, x + 1, y, to_fill);
		flood_fill(map, x - 1, y, to_fill);
		flood_fill(map, x, y + 1, to_fill);
		flood_fill(map, x, y - 1, to_fill);
	}
}

static t_map	to_flood_fill(t_map map)
{
	t_map	temp_map;
	t_pos	player_pos;

	player_pos = find_pos(map, PLAYER);
	temp_map.count_c = 0;
	temp_map.count_e = 0;
	temp_map.count_p = 0;
	temp_map.strs = ft_strsdup(map.strs);
	temp_map.height = map.height;
	temp_map.width = map.width;
	flood_fill(&temp_map, player_pos.x, player_pos.y, '2');
	return (temp_map);
}

int	check_flood_fill(t_map map)
{
	t_map	temp_map;

	temp_map = to_flood_fill(map);
	if (temp_map.count_c != map.count_c)
		ft_putstr_fd("ERROR\n: Player can't find Collectible.\n", 2);
	else if (temp_map.count_e != map.count_e)
		ft_putstr_fd("ERROR\n: Player can't find Exit.\n", 2);
	else
	{
		ft_putstr_fd("Flood fill checked.\n", 1);
		ft_free_strs(temp_map.strs);
		return (1);
	}
	ft_free_strs(temp_map.strs);
	return (0);
}
