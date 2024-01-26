/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:00:16 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/27 11:07:34 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*is_delete;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		is_delete = *lst;
		del(is_delete->content);
		(*lst) = (*lst)->next;
		free(is_delete);
	}
}
