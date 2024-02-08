/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:13 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/21 17:27:41 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**read_map_file(const char *file_name)
{
	if (!(ft_strlastncmp(file_name, ".ber", ft_strlen(".ber"))))
		return (ft_read_file(file_name));
	else
	{
		ft_putstr_fd("Error\n: file name is not compare .ber\n", 2);
		exit(1);
	}
}

void	count_obj_in_map(t_map *map)
{
	size_t	c;
	size_t	p;
	size_t	e;
	size_t	i;

	c = 0;
	p = 0;
	e = 0;
	i = 0;
	while (map->strs[i])
	{
		c = c + ft_strcchr(map->strs[i], 'C');
		p = p + ft_strcchr(map->strs[i], 'P');
		e = e + ft_strcchr(map->strs[i], 'E');
		i++;
	}
	map->count_c = c;
	map->count_e = e;
	map->count_p = p;
}

t_map	*map_init(int argc, char const *argv[])
{
	t_map	*map;
	char	**strs;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n: Please add only one argumant.\n", 2);
		exit(1);
	}
	strs = read_map_file(argv[1]);
	if (strs == NULL)
		print_error(strs, ME_NOT_FREE, M_MALLOC_ERROR);
	map = malloc(sizeof(t_map));
	if (!map)
		print_error(strs, ME_MODE_STRS, M_MALLOC_ERROR);
	map->strs = strs;
	map->height = ft_count_line_fd(argv[1]);
	map->width = ft_strlen(strs[0]);
	count_obj_in_map(map);
	map_validate(map);
	return (map);
}
