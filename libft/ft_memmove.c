/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:23:12 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/25 10:30:30 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	if (ptr_dest == ptr_src || len == 0)
		return (dest);
	if (ptr_dest < ptr_src)
	{
		while (len--)
		{
			*ptr_dest++ = *ptr_src++;
		}
	}
	else
	{
		ptr_dest = ptr_dest + len;
		ptr_src = ptr_src + len;
		while (len--)
		{
			*(--ptr_dest) = *(--ptr_src);
		}
	}
	return (dest);
}
