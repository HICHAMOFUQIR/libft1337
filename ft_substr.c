/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:23:39 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/27 16:22:11 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocate(char const *s, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	while (i < len && s[i] != '\0')
	{
		i++;
	}
	p = malloc(i + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*empty;

	s_len = 0;
	if (s == NULL)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
	{
		empty = malloc(1);
		if (empty == NULL)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	return (ft_allocate(s + start, len));
}
