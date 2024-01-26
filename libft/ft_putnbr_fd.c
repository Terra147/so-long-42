/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:43:24 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/26 13:05:00 by awadeng          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	str[15];
	long	ln;
	size_t	len;

	ln = n;
	len = ft_intlen(ln);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		ft_putstr_fd(str, fd);
		return ;
	}
	if (ln < 0)
	{
		str[0] = '-';
		ln = -(ln);
	}
	while (ln > 0)
	{
		str[--len] = (ln % 10) + '0';
		ln = ln / 10;
	}
	ft_putstr_fd(str, fd);
}
