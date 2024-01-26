/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:16:48 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/28 12:25:46 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_c;

	last_c = NULL;
	while (*str)
	{
		if (*str == (char) c)
			last_c = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (last_c);
}
