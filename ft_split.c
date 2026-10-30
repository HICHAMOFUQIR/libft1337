/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:00:01 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/29 20:44:51 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 1;
	while (*s)
	{
		if (*s == c)
			word = 1;
		else if (word)
		{
			count++;
			word = 0;
		}
		s++;
	}
	return (count);
}

static char	*ft_allocate(char const *s, int len)
{
	char	*p;
	int		i;

	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**ft_create_array(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (malloc((ft_count_words(s, c) + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	char		**arr;
	char const	*start;

	arr = ft_create_array(s, c);
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		start = s;
		i = 0;
		while (*s && *s != c && ++i)
			s++;
		arr[j] = ft_allocate(start, i);
		if (arr[j++] == NULL)
			return (ft_free(arr), NULL);
	}
	arr[j] = NULL;
	return (arr);
}
