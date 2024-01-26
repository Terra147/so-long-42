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
#include <string.h>

int	main(int argc, char const *argv[])
{
	t_game *game;
	int i = 0;
	game = start(argc, argv);
	ft_printf("========== Main =======\n");
	while (game->map->strs[i])
	{
		ft_printf("%s\n", game->map->strs[i]);
		i++;
	}
	ft_printf("P pos: x = %d, y = %d\n", game->player_pos.x, game->player_pos.y);
	ft_printf("E pos: x = %d, y = %d\n", game->exit_pos.x, game->exit_pos.y);
	ft_printf("Get C = %d, Walked = %d\n", game->get_c, game->walk_count);
	ft_free_strs(game->map->strs);
	free(game->map);
	free(game);
	return (0);
}
