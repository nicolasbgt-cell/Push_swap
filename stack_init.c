/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:07:54 by nbigot          #+#    #+#             */
/*   Updated: 2026/06/23 13:33:11 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_init(char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	i = 1 + ft_count_modes(argv);
	while (argv[i])
	{
		new = stack_new(ft_atoi(argv[i]));
		stack_add_back(&stack, new);
		i++;
	}
	return (stack);
}

static int	get_bench(char **argv)
{
	if ((ft_strcmp(argv[1], "--bench") == 0)
		|| (ft_strcmp(argv[2], "--bench") == 0))
		return (1);
	else
		return (0);
}

static float	get_disorder(t_stack *stack)
{
	t_stack	*curr;
	float	mistakes;
	float	total_pairs;
	float	disorder;

	mistakes = 0;
	total_pairs = 0;
	disorder = 0;
	curr = stack;
	while (curr->next != NULL)
	{
		total_pairs += 1;
		if (curr->value > curr->next->value)
			mistakes += 1;
		curr = curr->next;
	}
	disorder = mistakes / total_pairs;
	return (disorder);
}

static int	get_strategy(char **argv)
{
	if (ft_strcmp(argv[1], "--simple") == 0
		|| ft_strcmp(argv[2], "--simple") == 0)
		return (1);
	else if (ft_strcmp(argv[1], "--medium") == 0
		|| ft_strcmp(argv[2], "--medium") == 0)
		return (2);
	else if (ft_strcmp(argv[1], "--complex") == 0
		|| ft_strcmp(argv[2], "--complex") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "--adaptive") == 0
		|| ft_strcmp(argv[2], "--adaptive") == 0)
		return (4);
	else
		return (4);
}

static int	get_count_only(char **argv)
{
	if (ft_strcmp(argv[1], "--count-only") == 0)
		return (1);
	else
		return (0);
}

t_data	**data_init(char **argv)
{
	t_data	**data;
	int		i;

	i = 0;
	data = (t_data **)malloc(sizeof(t_data *));
	if (!data)
		return (NULL);
	*data = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return (NULL);
	(*data)->a = stack_init(argv);
	(*data)->b = NULL;
	(*data)->bench = get_bench(argv);
	(*data)->verbose = 1;
	(*data)->count_only = get_count_only(argv);
	if ((*data)->count_only == 1)
		(*data)->verbose = 0;
	(*data)->disorder = get_disorder((*data)->a);
	(*data)->strategy = get_strategy(argv);
	while (i < 11)
	{
		(*data)->ops[i] = 0;
		i++;
	}
	return (data);
}
