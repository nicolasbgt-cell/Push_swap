/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:24:07 by nbigot          #+#    #+#             */
/*   Updated: 2026/06/23 13:45:08 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_strategy(t_data *data)
{
	if (data->strategy == 1)
		ft_putendl_fd("[bench] strategy: Simple / O(n^2)", 2);
	else if (data->strategy == 2)
		ft_putendl_fd("[bench] strategy: Medium / O(n√n)", 2);
	else if (data->strategy == 3)
		ft_putendl_fd("[bench] strategy: Complex / O(n log n)", 2);
	else if (data->strategy == 4)
	{
		if (data->disorder < 0.2)
			ft_putendl_fd("[bench] strategy: Adaptive / O(n^2)", 2);
		else if (data->disorder < 0.5)
			ft_putendl_fd("[bench] strategy: Adaptive / O(n√n)", 2);
		else
			ft_putendl_fd("[bench] strategy: Adaptive / 0(nlog n)", 2);
	}
}

void	put_total_ops(t_data *data)
{
	int	total_ops;
	int	i;

	total_ops = 0;
	i = 0;
	while (i < 11)
	{
		total_ops += data->ops[i];
		i++;
	}
	ft_printf("[bench] total_ops: %d\n", total_ops);
}

static void	put_each_op(t_data *data)
{
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", data->ops[0],
		data->ops[1], data->ops[2], data->ops[3], data->ops[4]);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->ops[5], data->ops[6], data->ops[7], data->ops[8],
		data->ops[9], data->ops[10]);
}

static void	put_disorder(t_data *data)
{
	float	rest;

	rest = (int)(data->disorder * 10000) % 100;
	if (rest == 0)
		ft_printf("[bench] disorder: %d.%d0%%\n",
			(int)(data->disorder * 100), (int)rest);
	else
		ft_printf("[bench] disorder: %d.%d%%\n",
			(int)(data->disorder * 100), (int)rest);
}

void	put_bench(t_data *data)
{
	put_disorder(data);
	put_strategy(data);
	put_total_ops(data);
	put_each_op(data);
}

void	put_count_only(t_data *data)
{
	int	total_ops;
	int	i;

	total_ops = 0;
	i = 0;
	while (i < 11)
	{
		total_ops += data->ops[i];
		i++;
	}
	ft_printf("%d\n", total_ops);
}
