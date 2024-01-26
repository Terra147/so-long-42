/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:58:02 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/23 21:58:02 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strslen(char **strs)
{
	size_t	count;
	int		i;

	count = 0;
	if (!strs)
		return (count);
	i = 0;
	while (strs[i])
		count = count + ft_strlen(strs[i++]);
	return (count);
}
