/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:08:00 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/28 12:20:14 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcchr(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == (char)c)
			count++;
		str++;
	}
	return (count);
}
