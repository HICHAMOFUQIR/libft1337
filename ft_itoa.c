/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:54:51 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/29 20:45:19 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		sign;
	int		count;
	long	temp;

	if (n == 0)
		return (2);
	sign = 0;
	count = 0;
	temp = n;
	if (temp < 0)
	{
		sign++;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	return (count + sign + 1);
}

static char	*ft_reverse(char *str)
{
	int		len;
	int		i;
	int		j;
	char	temp;

	len = 0;
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[len])
		len++;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	temp;
	int		i;
	char	*p;

	temp = n;
	i = 0;
	p = malloc(ft_len(n));
	if (p == NULL)
		return (NULL);
	if (temp == 0)
		return (p[0] = '0', p[1] = '\0', p);
	if (temp < 0)
	{
		p[i++] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		p[i++] = (temp % 10) + 48;
		temp /= 10;
	}
	p[i] = '\0';
	return (ft_reverse(p));
}
