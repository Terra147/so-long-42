/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:24:55 by awadeng           #+#    #+#             */
/*   Updated: 2023/09/20 08:52:56 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		flags_res;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			flags_res = type_process(*(++str), &args);
			if (flags_res == -1)
				return (-1);
			count = count + flags_res;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	char *c = "5555";
	int	ft_res = ft_printf("%p\n", NULL);
	printf("res ft_printf = %d\n", ft_res);
	int ori = printf("%p\n", NULL);
	printf("res ft_printf = %d\n", ori);
	return (0);
}
*/
