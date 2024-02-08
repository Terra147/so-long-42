/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:37:15 by awadeng           #+#    #+#             */
/*   Updated: 2024/02/08 12:26:18 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_read_file(const char *file_name)
{
	int		fd;
	char	*str;
	char	**strs;
	int		i;

	strs = malloc(sizeof(char *) * (ft_count_line_fd(file_name) + 1));
	if (!strs)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		if (ft_strchr(str, '\n'))
			str[ft_strlen(str) - 1] = '\0';
		strs[i++] = str;
		str = get_next_line(fd);
	}
	strs[i] = NULL;
	close(fd);
	return (strs);
}
