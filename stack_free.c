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
