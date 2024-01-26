/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 20:47:57 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/26 13:15:56 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*trimmed;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (end > s1 && ft_strchr(set, *end))
		end--;
	len = end - s1 + 1;
	trimmed = (char *)malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1, len + 1);
	return (trimmed);
}
