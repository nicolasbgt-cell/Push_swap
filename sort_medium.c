#include "push_swap.h"

static void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_stack(t_stack *a, int size)
{
	int		*values;
	int		i;
	t_stack	*node;

	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	node = a;
	i = 0;
	while (i < size)
	{
		values[i++] = node->value;
		node = node->next;
	}
	bubble_sort_array(values, size);
	node = a;
	while (node)
	{
		i = 0;
		while (i < size && node->value != values[i])
			i++;
		node->value = i;
		node = node->next;
	}
	free(values);
}

static int	find_max_index(t_stack *stack)
{
	int		max;
	int		max_index;
	int		i;
	t_stack	*tmp;

	if (stack == NULL)
		return (-1);
	max = stack->value;
	max_index = 0;
	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (max_index);
}

static void	push_chunks(t_data *data, int size, int chunk_size)
{
	int	pushed;
	int	chunk;

	pushed = 0;
	chunk = 0;
	while (pushed < size)
	{
		if (data->a && data->a->value < (chunk + 1) * chunk_size)
		{
			pb(data, data->verbose);
			pushed++;
		}
		else if (data->a)
			ra(data, data->verbose);
		if (pushed >= (chunk + 1) * chunk_size)
			chunk++;
	}
}

void	sort_medium(t_data *data)
{
	int	size;
	int	chunk_size;
	int	pos;

	if (is_sorted(data->a))
		return ;
	size = stack_size(data->a);
	normalize_stack(data->a, size);
	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	push_chunks(data, size, chunk_size);
	while (data->b != NULL)
	{
		pos = find_max_index(data->b);
		if (pos <= stack_size(data->b) / 2)
			while (pos-- > 0)
				rb(data, data->verbose);
		else
			while (pos++ < stack_size(data->b))
				rrb(data, data->verbose);
		pa(data, data->verbose);
	}
}
