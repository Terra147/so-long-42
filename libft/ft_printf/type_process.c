/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:23:08 by awadeng           #+#    #+#             */
/*   Updated: 2023/09/20 08:55:59 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_c(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return (write(1, &c, 1));
}

static int	type_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

static int	type_int(va_list *args)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*args, int));
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	if (len == -1)
		return (-1);
	return (len);
}

static int	type_u_int(va_list *args)
{
	char	*str;
	int		len;

	str = ft_utoa(va_arg(*args, unsigned int));
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	if (len == -1)
		return (-1);
	return (len);
}

int	type_process(const char c, va_list *args)
{
	if (c == 'c')
		return (type_c(args));
	else if (c == 's')
		return (type_str(args));
	else if (c == 'p')
		return (ft_ulnbr_base(args, "0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (type_int(args));
	else if (c == 'u')
		return (type_u_int(args));
	else if (c == 'x')
		return (ft_nbr_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_nbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}
