/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:16:56 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/29 14:39:11 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*Counts the number of nodes in the list.*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*lst;

	lst = NULL;
	lst = ft_lstnew("world");
	ft_lstadd_front(&lst, ft_lstnew("hello"));
	ft_lstadd_front(&lst, ft_lstnew((void*)2));
	printf("size: %d\n", ft_lstsize(lst));
}*/
