/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:07:40 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/23 13:18:46 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_find(const char *big, const char *little, size_t len)
{
    size_t i;

    i = 0;
    while (little[i])
    {
        if (i >= len || big[i] != little[i])
            return (0);
        i++;
    }
    return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (big == NULL || little == NULL || *little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && *big)
	{
		if (*big == little[0])
		{
			if (ft_find(big, little, len - i))
				return ((char *)big);
		}
		big++;
		i++;
	}
	return (NULL);
}
