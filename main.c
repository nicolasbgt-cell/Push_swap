#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	**data;

	check_args(argc, argv);
	data = data_init(argv);
	index_stack(&(*data)->a);
	sort_data(data);
	if ((*data)->bench == 1 && (*data)->disorder > 0)
		put_bench(*data);
	if ((*data)->count_only == 1)
		put_count_only(*data);
	data_free(data);
	return (0);
}
