#include "push_swap.h"

void	rra(t_data *data, int verbose)
{
	t_stack	*last;
	t_stack	*before_last;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	before_last = data->a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = data->a;
	data->a = last;
	data->ops[8]++;
	if (verbose)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int verbose)
{
	t_stack	*last;
	t_stack	*before_last;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	before_last = data->b;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = data->b;
	data->b = last;
	data->ops[9]++;
	if (verbose)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	int	can_reverse_a;
	int	can_reverse_b;

	can_reverse_a = (data->a != NULL && data->a->next != NULL);
	can_reverse_b = (data->b != NULL && data->b->next != NULL);
	if (can_reverse_a && can_reverse_b)
	{
		rra(data, 0);
		rrb(data, 0);
		write(1, "rrr\n", 4);
		data->ops[10]++;
	}
	else if (can_reverse_a)
		rra(data, 1);
	else if (can_reverse_b)
		rrb(data, 1);
}
