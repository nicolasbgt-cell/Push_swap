/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:44:36 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/11 10:05:57 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Adds the node ’new’ at the end of the list.*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (lst != NULL && *lst != NULL)
	{
		element = *lst;
		element = ft_lstlast(*lst);
		element->next = new;
		return ;
	}
	*lst = new;
}
