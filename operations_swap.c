#include "push_swap.h"

void	sa(t_data *data, int verbose)
{
	t_stack	*first;
	t_stack	*second;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	first = data->a;
	second = data->a->next;
	data->a = second;
	first->next = second->next;
	second->next = first;
	data->ops[0]++;
	if (verbose)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int verbose)
{
	t_stack	*first;
	t_stack	*second;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	first = data->b;
	second = data->b->next;
	data->b = second;
	first->next = second->next;
	second->next = first;
	data->ops[1]++;
	if (verbose)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	int	can_swap_a;
	int	can_swap_b;

	can_swap_a = (data->a != NULL && data->a->next != NULL);
	can_swap_b = (data->b != NULL && data->b->next != NULL);
	if (can_swap_a && can_swap_b)
	{
		sa(data, 0);
		sb(data, 0);
		data->ops[2]++;
	}
	else if (can_swap_a)
		sa(data, 1);
	else if (can_swap_b)
		sb(data, 1);
}
