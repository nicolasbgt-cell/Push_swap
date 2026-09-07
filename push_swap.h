#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_printf(const char *fmt, ...);

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			count_only;
	int			verbose;
	int			bench;
	int			strategy;
	int			ops[11];
	float		disorder;
}	t_data;

void	sa(t_data *data, int verbose);
void	sb(t_data *data, int verbose);
void	ss(t_data *data);
void	pa(t_data *data, int verbose);
void	pb(t_data *data, int verbose);
void	ra(t_data *data, int verbose);
void	rb(t_data *data, int verbose);
void	rr(t_data *data);
void	rra(t_data *data, int verbose);
void	rrb(t_data *data, int verbose);
void	rrr(t_data *data);
void	put_count_only(t_data *data);

void	check_args(int argc, char **argv);
void	ft_error(char *error);
int		is_digit(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_count_modes(char **argv);

t_data	**data_init(char **argv);
t_stack	*stack_new(int value);
void	index_stack(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
int		find_min_index(t_stack *stack);
int		is_sorted(t_stack *stack);
void	stack_free(t_stack **stack);
void	data_free(t_data **data);
void	sort_simple(t_data *data);
void	sort_medium(t_data *data);
void	sort_complex(t_data **data);
void	sort_data(t_data **data);
void	put_bench(t_data *data);
void	put_total_ops(t_data *data);

#endif
