/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:51:04 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/27 16:22:02 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_all_set(char const *arr, char const *set)
{
	while (*arr)
	{
		if (ft_is_in_set(*arr, set) == 0)
			return (0);
		arr++;
	}
	return (1);
}

static size_t	ft_trim_len(char const *s, char const *set)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		if (ft_is_in_set(s[count], set)
			&& ft_all_set(&s[count], set))
			break ;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	start;
	size_t	i;
	char	*p;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	count = ft_trim_len(&s1[start], set);
	p = malloc(count + 1);
	if (p == NULL)
		return (NULL);
	while (s1[start])
	{
		if (ft_is_in_set(s1[start], set) && ft_all_set(&s1[start], set))
			break ;
		p[i++] = s1[start++];
	}
	p[i] = '\0';
	return (p);
}
