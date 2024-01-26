/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:06:12 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/26 10:31:08 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	is_negative(long *ln, char *str)
{
	if (*ln < 0)
	{
		str[0] = '-';
		*ln = -(*ln);
	}
}

char	*ft_itoa(int n)
{
	long	ln;
	size_t	len;
	char	*str;

	ln = n;
	len = ft_intlen(ln);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	is_negative(&ln, str);
	while (ln > 0)
	{
		str[--len] = (ln % 10) + '0';
		ln = ln / 10;
	}
	return (str);
}
