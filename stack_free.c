/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:10:56 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/20 08:13:02 by nbigot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	data_free(t_data **data)
{
	stack_free((&(*data)->a));
	stack_free((&(*data)->b));
	free(*data);
	free(data);
}
