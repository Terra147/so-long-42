/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:52:38 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/28 10:59:47 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*memory_block;

	if (size == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	else if (size && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	memory_block = malloc(total_size);
	if (memory_block == NULL)
		return (NULL);
	ft_memset(memory_block, 0, total_size);
	return (memory_block);
}
