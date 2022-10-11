#include "push_swap.h"
#include <assert.h>

#define AAA 0b000
#define AAD 0b001 
#define ADA 0b010 
#define ADD 0b011 
#define DAA 0b100
#define DAD 0b101
#define DDA 0b110
#define DDD 0b111

#define EMPTY 0b1000


enum e_ps_prime_num_pos {
	A_STACK_TOP,
	B_STACK_TOP,
	A_STACK_REAR,
	B_STACK_REAR
};

int	ps_status(
	t_deque_run *a_run,
	t_deque_run *b_run
)
{
	int	status;

	if (ft_deque_run_peek_back(a_run).ord == None)
		return (EMPTY | AAA);
	if (ft_deque_run_peek_back(b_run).ord == None)
		return (EMPTY | DDD);
	status = 0;
	status |= ft_deque_run_peek_back(a_run).ord << 2;
	status |= ft_deque_run_peek_back(b_run).ord << 1;
	status |= ft_deque_run_peek_front(a_run).ord << 0;

	return (status);
}

enum e_ps_prime_num_pos	ps_max_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack
)
{
	const int	a_top = a_stack->deque[a_stack->top - 1];
	const int	b_top = b_stack->deque[b_stack->top - 1];
	const int	a_rear = a_stack->deque[a_stack->rear];
	int			ret;

	if (a_top >= b_top && a_top >= a_rear)
		return (A_STACK_TOP);
	else if (b_top >= a_top && b_top >= a_rear)
		return (B_STACK_TOP);
	else
		return (A_STACK_REAR);
}

enum e_ps_prime_num_pos	ps_min_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack
)
{
	const int	a_top = ft_deque_typesymbol_peek_back(a_stack);
	const int	b_top = ft_deque_typesymbol_peek_back(b_stack);
	const int	a_rear = ft_deque_typesymbol_peek_front(a_stack);
	int			ret;

	if (a_top <= b_top && a_top <= a_rear)
		return (A_STACK_TOP);
	else if (b_top <= a_top && b_top <= a_rear)
		return (B_STACK_TOP);
	else
		return (A_STACK_REAR);
}

void	push_run(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	t_run	new_run;
	int		temp_num;
	int		i;

	new_run = ft_deque_run_pop_back(a_stack->runs);
	new_run = (t_run){new_run.len, new_run.ord ^ 1};
	i = -1;
	while (++i < new_run.len)
	{
		temp_num = ft_deque_typesymbol_pop_back(a_stack->numbers);
		ft_deque_typesymbol_push_back(b_stack->numbers, temp_num);
	}
	ft_deque_run_push_back(b_stack->runs, new_run);
}

#define NUM_POS_MASK 0b111

void	merge(
	t_ps_stack *a_stack,
	t_ps_stack *b_stack,
	int status,
	int len
)
{
	int			prime_num_pos;
	const int	num_pos_status = status & NUM_POS_MASK;

	if (num_pos_status == AAA || num_pos_status == AAD
		|| num_pos_status == ADD || num_pos_status == DAA)
		prime_num_pos = ps_max_num_pos(a_stack->numbers, b_stack->numbers);
	else
		prime_num_pos = ps_min_num_pos(a_stack->numbers, b_stack->numbers);
	if (prime_num_pos == A_STACK_TOP)
	{
		pb(a_stack->numbers, b_stack->numbers);
		rb(a_stack->numbers, b_stack->numbers);
	}
	else if (prime_num_pos == B_STACK_TOP)
	{
		rb(a_stack->numbers, b_stack->numbers);
	}
	else if (prime_num_pos == A_STACK_REAR)
	{
		rra(a_stack->numbers, b_stack->numbers);
		pb(a_stack->numbers, b_stack->numbers);
		rb(a_stack->numbers, b_stack->numbers);
	}
	else {
		assert(0);
	}

	merge(a_stack, b_stack, status, len - 1);
}

t_run	merge_run(
	t_ps_stack *a_stack,
	t_ps_stack *b_stack,
	int status
)
{
	t_run		ret;
	const int	num_pos_status = status & NUM_POS_MASK;

	if (num_pos_status == AAA || num_pos_status == AAD
		|| num_pos_status == ADD || num_pos_status == DAA)
		ret.ord = Ascending;
	else
		ret.ord = Descending;
	if (num_pos_status == AAA || num_pos_status == DDD)
	{
		ret.len = ft_deque_run_pop_back(a_stack->runs).len + 
			ft_deque_run_pop_back(b_stack->runs).len;
	}
	else if (num_pos_status == AAD || num_pos_status == DDA)
	{
		ret.len = ft_deque_run_pop_back(a_stack->runs).len + 
			ft_deque_run_pop_back(b_stack->runs).len +
			ft_deque_run_pop_front(a_stack->runs).len;
	}
	else if (num_pos_status == ADA || num_pos_status == DAD)
	{
		ret.len = ft_deque_run_pop_back(b_stack->runs).len +
			ft_deque_run_pop_front(a_stack->runs).len;
	}
	else {
		ret.len = ft_deque_run_pop_back(a_stack->runs).len +
			ft_deque_run_pop_front(a_stack->runs).len;
	}
	return (ret);
}

void	push_swap(
	t_deque_typesymbol *a_nums,
	t_deque_typesymbol *b_nums,
	t_deque_run *a_runs,
	t_deque_run *b_runs
)
{
	int	status;
	int	prime_num_pos;
	int	i;
	t_ps_stack	a_stack = {a_nums, a_runs};
	t_ps_stack	b_stack = {b_nums, b_runs};
	t_run	new_run;

	status = ps_status(a_runs, b_runs);
	if (status & EMPTY)
	{
		push_run(&a_stack, &b_stack);
		return ;
	}
	else
	{
		new_run = merge_run(&a_stack, &b_stack, status);
		ft_deque_run_push_back(b_stack.runs, new_run);
		merge(&a_stack, &b_stack, status, new_run.len);
	}
}
