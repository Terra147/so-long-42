/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:25:38 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 23:28:12 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined(__linux__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
# elif defined(_WIN32)
#  define PTRNULL "0"
# endif

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
char	*ft_utoa(unsigned int n);
int		ft_nbr_base(unsigned int nbr, char *base);
int		ft_ulnbr_base(va_list *args, char *base);
int		type_process(const char c, va_list *args);
#endif
