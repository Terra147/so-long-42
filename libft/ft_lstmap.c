/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:13:31 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/28 10:48:38 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_new_lst;

	first_new_lst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&first_new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&first_new_lst, new_lst);
		lst = lst->next;
	}
	return (first_new_lst);
}
