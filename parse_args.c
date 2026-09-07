#include "push_swap.h"
#include <stdlib.h>

static int	is_valid_int(char *str)
{
	unsigned int	i;
	unsigned int	sign;
	unsigned int	is_int;

	i = 0;
	sign = 0;
	is_int = 1;
	while (str[i] && is_int)
	{
		if (str[i] == '-' && sign < 1)
			sign++;
		else if (is_digit(str[i]) == 0)
			is_int = 0;
		i++;
	}
	return (is_int);
}

static int	is_double(char *element, char **args, int i)
{
	int	num;

	num = ft_atoi(element);
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_modes(char **argv)
{
	int	modes;

	modes = 0;
	{
		if (ft_strcmp(argv[1], "--simple") == 0
			|| ft_strcmp(argv[1], "--medium") == 0
			|| ft_strcmp(argv[1], "--complex") == 0
			|| ft_strcmp(argv[1], "--adaptive") == 0
			|| ft_strcmp(argv[1], "--bench") == 0
			|| ft_strcmp(argv[1], "--count-only") == 0)
		{
			modes += 1;
			if (argv[2] && ft_strcmp(argv[1], "--bench") == 0
				&& (ft_strcmp(argv[2], "--simple") == 0
					|| ft_strcmp(argv[2], "--medium") == 0
					|| ft_strcmp(argv[2], "--complex") == 0
					|| ft_strcmp(argv[2], "--adaptive") == 0
					|| ft_strcmp(argv[2], "--count-only") == 0 ))
				modes += 1;
		}
		else
			return (0);
	}
	return (modes);
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	modes;

	if (argc <= 2)
		exit(0);
	i = 1;
	modes = ft_count_modes(argv);
	i += modes;
	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			ft_error("Error");
		if (is_double(argv[i], argv, i))
			ft_error("Error");
		else
			i++;
	}
}
