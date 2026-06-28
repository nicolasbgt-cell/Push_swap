/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:05:50 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/28 12:14:35 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

Adds the node ’new’ at the beginning of the list.

void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("element %d: %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*new_element;

	lst = NULL;
	new_element = ft_lstnew("Test");
	ft_lstadd_front(&lst, new_element);
	ft_lstadd_front(&lst, ft_lstnew("This is a"));
	print_list(lst);
	return (0);
}*/
