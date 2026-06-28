/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:20:55 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/28 12:30:52 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Iterates through the list ’lst’, applies the function
’f’ to each node’s content, and creates a new list
resulting of the successive applications of the
function ’f’. The ’del’ function is used to delete
the content of a node if needed.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_res;
	t_list	*node;

	lst_res = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_res, node);
		lst = lst->next;
	}
	return (lst_res);
}
