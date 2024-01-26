/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:04:53 by awadeng           #+#    #+#             */
/*   Updated: 2023/09/06 12:20:30 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_base(char *p_base1)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (p_base1[i])
	{
		if (p_base1[i] == '+' || p_base1[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (p_base1[i])
	{
		j = i + 1;
		while (p_base1[j])
		{
			if (p_base1[i] == p_base1[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	print_str_revert(char *str)
{
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		count++;
		len--;
	}
	return (count);
}

static int	ft_print_nbr(unsigned int nbr, char *base)
{
	int		len_base;
	int		result;
	char	char_res[20];
	int		i;

	i = 0;
	len_base = ft_strlen(base);
	result = 0;
	while (nbr != 0)
	{
		result = (nbr % len_base);
		char_res[i] = base[result];
		nbr = nbr / len_base;
		i++;
	}
	char_res[i] = '\0';
	return (print_str_revert(char_res));
}

int	ft_nbr_base(unsigned int nbr, char *base)
{
	if (ft_strlen(base) <= 1)
		return (-1);
	if (ft_check_base(base))
	{
		if (nbr == 0)
			return (write(1, &base[0], 1));
		else
			return (ft_print_nbr(nbr, base));
	}
	else
		return (-1);
}
