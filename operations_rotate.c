/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:09:36 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/23 18:29:08 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int verbose)
{
	t_stack	*first;
	t_stack	*last;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	first = data->a;
	data->a = data->a->next;
	last = data->a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	data->ops[5]++;
	if (verbose)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int verbose)
{
	t_stack	*first;
	t_stack	*last;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	first = data->b;
	data->b = data->b->next;
	last = data->b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	data->ops[6]++;
	if (verbose)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	int	can_rotate_a;
	int	can_rotate_b;

	can_rotate_a = (data->a != NULL && data->a->next != NULL);
	can_rotate_b = (data->b != NULL && data->b->next != NULL);
	if (can_rotate_a && can_rotate_b)
	{
		ra(data, 0);
		rb(data, 0);
		write(1, "rr\n", 3);
		data->ops[7]++;
	}
	else if (can_rotate_a)
		ra(data, 1);
	else if (can_rotate_b)
		rb(data, 1);
}
