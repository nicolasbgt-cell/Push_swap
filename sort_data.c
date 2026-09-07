#include "push_swap.h"

static void	sort_adaptive(t_data **data)
{
	float	disorder;

	disorder = (*data)->disorder;
	if (stack_size((*data)->a) <= 5)
	{
		sort_simple(*data);
		return ;
	}
	else if (disorder < 0.2)
		sort_simple(*data);
	else if (disorder < 0.5)
		sort_medium(*data);
	else
		sort_complex(data);
}

void	sort_data(t_data **data)
{
	int	strategy;

	if (is_sorted((*data)->a))
		return ;
	strategy = (*data)->strategy;
	if (strategy == 1)
		sort_simple(*data);
	if (strategy == 2)
		sort_medium(*data);
	if (strategy == 3)
		sort_complex(data);
	if (strategy == 4)
		sort_adaptive(data);
}
