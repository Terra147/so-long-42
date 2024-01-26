/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:23:08 by awadeng           #+#    #+#             */
/*   Updated: 2023/08/26 09:05:01 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c, size_t *index)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*word;

	while (s[*index] == c && s[*index])
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index])
		(*index)++;
	end = (*index);
	word = (char *)malloc(end - start + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_allocated_memory(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_splited;
	size_t	count;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	count = word_count(s, c);
	str_splited = (char **)malloc((count + 1) * sizeof(char *));
	if (str_splited == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		str_splited[i] = get_word(s, c, &j);
		if (str_splited[i] == NULL)
		{
			free_allocated_memory(str_splited, i);
			return (NULL);
		}
		i++;
	}
	str_splited[i] = NULL;
	return (str_splited);
}
