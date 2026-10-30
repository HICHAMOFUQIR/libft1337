/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houfqir <houfqir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:38:15 by houfqir           #+#    #+#             */
/*   Updated: 2026/10/23 13:28:48 by houfqir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (lst == NULL || new == NULL)
		return ;
	head = ft_lstlast(*lst);
	if (head == NULL)
	{
		*lst = new;
		return ;
	}
	head->next = new;
}
