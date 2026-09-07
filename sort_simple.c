#include "push_swap.h"

static void	bring_min_to_top(t_data *data)
{
	int	pos;
	int	size;
	int	i;

	pos = find_min_index(data->a);
	size = stack_size(data->a);
	i = 0;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(data, data->verbose);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(data, data->verbose);
			i++;
		}
	}
}

static void	sort_3(t_data *data)
{
	t_stack	*head;

	head = data->a;
	if (head->value > head->next->value)
		sa(data, data->verbose);
	head = data->a;
	if (head->next->value > head->next->next->value)
		rra(data, data->verbose);
	head = data->a;
	if (head->value > head->next->value)
		sa(data, data->verbose);
}

void	sort_simple(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (stack_size(data->a) == 3)
		sort_3(data);
	else
	{
		while (stack_size(data->a) > 1)
		{
			bring_min_to_top(data);
			pb(data, data->verbose);
		}
		while (data->b != NULL)
			pa(data, data->verbose);
	}
}
