/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:53:57 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/27 09:28:28 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

 *Allocates memory (using malloc(3)) and returns a new
node. The ’content’ member variable is initialized
with the given parameter ’content’. The variable
’next’ is initialized to NULL.*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	t_list	*new_element;

	new_element = ft_lstnew("test");
	printf("new element: %s\n", (char *)new_element->content);
	return (0);
}*/
