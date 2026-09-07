#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_min_index(t_stack *stack)
{
	int		min;
	int		min_index;
	int		i;
	t_stack	*tmp;

	if (stack == NULL)
		return (-1);
	min = stack->value;
	min_index = 0;
	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_index);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL || stack->next == NULL)
		return (1);
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
