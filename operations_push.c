/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:53:49 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/23 18:27:48 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data, int verbose)
{
	t_stack	*node;

	if (data->b == NULL)
		return ;
	node = data->b;
	data->b = data->b->next;
	node->next = data->a;
	data->a = node;
	data->ops[3]++;
	if (verbose)
		write(1, "pa\n", 3);
}

void	pb(t_data *data, int verbose)
{
	t_stack	*node;

	if (data->a == NULL)
		return ;
	node = data->a;
	data->a = data->a->next;
	node->next = data->b;
	data->b = node;
	data->ops[4]++;
	if (verbose)
		write(1, "pb\n", 3);
}
