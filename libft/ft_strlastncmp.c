/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlastncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:07:31 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/23 15:13:38 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlastncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	while (*str1)
		str1++;
	while (*str2)
		str2++;
	str1--;
	str2--;
	i = 0;
	while ((*str1 || *str2) && i < n)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1--;
		str2--;
		i++;
	}
	return (0);
}
