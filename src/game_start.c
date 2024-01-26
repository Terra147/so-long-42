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

static t_game	*starting(int argc, char const *argv[])
{
	t_map	*map;
	t_game	*game;

	map = map_init(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_free_strs(map->strs);
		free(map);
		perror("ERROR\n");
		exit(1);
	}
	game->map = map;
	game->player_pos = find_pos(*map, PLAYER);
	game->exit_pos = find_pos(*map, EXIT);
	game->get_c = START;
	game->walk_count = START;
	return (game);
}

t_game	*start(int argc, char const *argv[])
{
	t_game	*game;

	game = starting(argc, argv);
	return (game);
}
