/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:26:39 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/23 13:37:14 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
