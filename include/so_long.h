/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:53:46 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/23 17:53:46 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "fcntl.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define START 0

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_c_fill
{
	size_t		count_e;
	size_t		count_c;
	size_t		count_p;
}	t_c_fill;

typedef struct s_map
{
	char			**strs;
	size_t			count_e;
	size_t			count_c;
	size_t			count_p;
	size_t			height;
	size_t			width;
}	t_map;

// Player position
typedef struct s_pos
{
	size_t			x;
	size_t			y;
}	t_pos;

typedef struct s_game
{
	t_pos	player_pos;
	t_map	*map;
	size_t	walk_count;
	size_t	get_c;
	t_pos	exit_pos;

}	t_game;

// map validate and init
t_map	*map_init(int argc, char const *argv[]);
void	map_validate(t_map *map);
int		check_flood_fill(t_map map);

t_pos	find_pos(t_map map, char find);

// game start
t_game	*start(int argc, char const *argv[]);

#endif
