/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:58:12 by awadeng           #+#    #+#             */
/*   Updated: 2024/01/22 22:59:57 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*check_lst(t_gnl **head, int fd, t_gnl *curr, t_gnl *new_lst)
{
	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
			break ;
		curr = curr->next;
	}
	if (!curr)
	{
		new_lst = (t_gnl *)malloc(sizeof(t_gnl));
		if (!new_lst)
			return (NULL);
		new_lst->fd = fd;
		new_lst->str = (char *)malloc(1);
		if (!new_lst->str)
		{
			free(new_lst);
			return (NULL);
		}
		*(new_lst->str) = '\0';
		new_lst->next = *head;
		*head = new_lst;
		return (*head);
	}
	return (curr);
}

int	read_line(t_gnl *curr, char *temp)
{
	char	*buffer;
	int		read_byte;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_byte = read(curr->fd, buffer, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buffer[read_byte] = '\0';
		temp = curr->str;
		curr->str = ft_strjoin(curr->str, buffer);
		if (!(curr->str))
		{
			free(temp);
			free(buffer);
			return (0);
		}
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		read_byte = read(curr->fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (read_byte >= 0);
}

char	*cut_new_line(char *pos, size_t *len, t_gnl *curr)
{
	char	*line;
	char	*temp;

	*pos = '\0';
	*len = ft_len_or_lcpy(0, 0, curr->str, 0);
	line = (char *)malloc(*len + 2);
	if (line == NULL)
		return (NULL);
	ft_len_or_lcpy(1, line, curr->str, *len + 1);
	ft_strlcat(line, "\n", *len + 2);
	temp = (char *)malloc(ft_len_or_lcpy(0, 0, (pos + 1), 0) + 1);
	if (temp == NULL)
	{
		free(line);
		return (NULL);
	}
	ft_len_or_lcpy(1, temp, pos + 1, ft_len_or_lcpy(0, 0, (pos + 1), 0) + 1);
	free(curr->str);
	curr->str = temp;
	return (line);
}

char	*cut_line(t_gnl **head, t_gnl *curr)
{
	char	*line;
	char	*pos;
	size_t	len;

	pos = ft_strchr(curr->str, '\n');
	if (pos)
		return (cut_new_line(pos, &len, curr));
	else if (*(curr->str))
	{
		len = ft_len_or_lcpy(0, 0, curr->str, 0);
		line = (char *)malloc(len + 1);
		if (line == NULL)
			return (NULL);
		ft_len_or_lcpy(1, line, curr->str, len + 1);
		delete_node(head, curr);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*curr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr = check_lst(&head, fd, NULL, NULL);
	if (!curr)
		return (NULL);
	if (!read_line(curr, NULL))
	{
		delete_node(&head, curr);
		return (NULL);
	}
	line = cut_line(&head, curr);
	if (!line)
		delete_node(&head, curr);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd1 = open("giant_line.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	int fd3 = open("file3.txt", O_RDONLY);
	char *line;

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		return (1);
	}

	// อ่านจาก fd1
	printf("Reading from fd1:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	// อ่านจาก fd2
	printf("\nReading from fd2:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	// อ่านจาก fd3
	printf("\nReading from fd3:\n");
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
*/
