/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:36:53 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/27 12:04:40 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*p;
	unsigned char			ch;

	i = 0;
	p = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
