/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:59:01 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 22:59:57 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	delete_node(t_gnl **head, t_gnl *curr)
{
	t_gnl	*temp;
	t_gnl	*prev;

	temp = *head;
	prev = NULL;
	if (temp != NULL && temp == curr)
	{
		*head = temp->next;
		free(temp->str);
		free(temp);
		return ;
	}
	while (temp != NULL && temp != curr)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		prev->next = temp->next;
		free(temp->str);
		free(temp);
	}
}

size_t	ft_len_or_lcpy(int mode, char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (mode == 0)
		return (src_len);
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
