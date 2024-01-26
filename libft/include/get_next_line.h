/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:01:11 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 23:10:01 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_len_or_lcpy(int mode, char *dest, const char *src, size_t size);

typedef struct s_gnl_lst
{
	int					fd;
	char				*str;
	struct s_gnl_lst	*next;
}		t_gnl;

char	*get_next_line(int fd);
char	*cut_new_line(char *pos, size_t *len, t_gnl *curr);
void	delete_node(t_gnl **head, t_gnl *curr);
#endif
