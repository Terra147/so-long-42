/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:24:34 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/21 17:24:50 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(t_map map)
{
	size_t	rectangle;
	size_t	strs_len;
	size_t	i;

	strs_len = ft_strslen(map.strs);
	i = 0;
	while (map.strs[i])
	{
		rectangle = ft_strlen(map.strs[i++]) * map.height;
		if (rectangle != strs_len)
		{
			ft_putstr_fd("Error\n: Map is not rectangle.\n", 2);
			return (0);
		}
	}
	return (1);
}

static int	count_check(t_map map)
{
	if (map.count_c < 1)
	{
		ft_putstr_fd("Error\n: Collectible less than 1 in map.\n", 2);
		return (0);
	}
	if (map.count_e != 1)
	{
		ft_putstr_fd("Error\n: Exit position is not 1 in map.\n", 2);
		return (0);
	}
	if (map.count_p != 1)
	{
		ft_putstr_fd("Error\n: Starting position is not 1 in map.\n", 2);
		return (0);
	}
	return (1);
}

static int	check_wall(t_map map)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = ft_strlen(map.strs[0]) - 1;
	while (map.strs[0][i])
	{
		if (map.strs[0][i] != '1' || map.strs[map.height - 1][i] != '1')
		{
			ft_putstr_fd("Error\n: Map is not closed by wall.\n", 2);
			return (0);
		}
		i++;
	}
	i = 0;
	while (map.strs[i])
	{
		if (map.strs[i][0] != '1' || map.strs[i][last] != '1')
		{
			ft_putstr_fd("Error\n: Map is not closed by wall.\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_only_chr(char **strs)
{
	size_t	i;
	char	*str;

	i = 0;
	while (strs[i])
	{
		str = ft_strtrim(strs[i], "01ECP");
		if (ft_strncmp(str, "", ft_strlen(str)))
		{
			ft_putstr_fd("Error\n: Map is only \"0,1,E,C,P\" Character.\n", 2);
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}

void	map_validate(t_map *map)
{
	if (!check_rectangle(*map) || !count_check(*map)
		|| !check_only_chr(map->strs) || !check_wall(*map)
		|| !check_flood_fill(*map))
	{
		ft_free_strs(map->strs);
		free(map);
		exit(1);
	}
	ft_putstr_fd("Map is OK.\n", 1);
}
