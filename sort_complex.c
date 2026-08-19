/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:42:57 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/20 08:55:53 by nbigot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_data **data)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = (*data)->a;
	size = stack_size((*data)->a);
	max_bits = get_max_bits((*data)->a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = (*data)->a;
			if (((head_a->index >> i) & 1) == 1)
				ra((*data), (*data)->verbose);
			else
				pb((*data), (*data)->verbose);
		}
		while (stack_size((*data)->b) != 0)
			pa((*data), (*data)->verbose);
		i++;
	}
}
