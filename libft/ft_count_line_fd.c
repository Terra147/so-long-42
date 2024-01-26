/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:42 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/23 17:14:26 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_line_fd(const char *file_name)
{
	size_t	count;
	char	*str;
	int		fd;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}
