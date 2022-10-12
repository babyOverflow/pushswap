#include <assert.h>
#include <limits.h>

#include "push_swap.h"
#include "libft.h"

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

enum e_ps_prime_num_pos	ps_min_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	int status
)
{
	enum e_ps_prime_num_pos	ret;
	const int				a_top = ft_deque_typesymbol_peek_back(a_stack);
	const int				b_top = ft_deque_typesymbol_peek_back(b_stack);
	const int				a_rear = ft_deque_typesymbol_peek_front(a_stack);
	int						min_num;

	min_num = INT_MAX;
	if (status == AAA || status == AAD || status == ADD)
		if (a_top < min_num)
			min_num = a_top;
	if (status == AAA || status == AAD || status == DAD)
		if (b_top < min_num)
			min_num = b_top;
	if (status == AAD || status == ADD || status == DAD)
		if (a_rear < min_num)
			min_num = a_rear;
	if (min_num == a_top)
		ret = A_STACK_TOP;
	else if (min_num == b_top)
		ret = B_STACK_TOP;
	else
		ret = A_STACK_REAR;
	return (ret);
}

enum e_ps_prime_num_pos	ps_max_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	int status
)
{
	enum e_ps_prime_num_pos	ret;
	const int				a_top = ft_deque_typesymbol_peek_back(a_stack);
	const int				b_top = ft_deque_typesymbol_peek_back(b_stack);
	const int				a_rear = ft_deque_typesymbol_peek_front(a_stack);
	int						max_num;

	max_num = INT_MIN;
	if (status == DDD || status == DDA || status == DAA)
		if (a_top > max_num)
			max_num = a_top;
	if (status == DDD || status == DDA || status == ADA)
		if (b_top > max_num)
			max_num = b_top;
	if (status == DDA || status == DAA || status == ADA)
		if (a_rear > max_num)
			max_num = a_rear;
	if (max_num == a_top)
		ret = A_STACK_TOP;
	else if (max_num == b_top)
		ret = B_STACK_TOP;
	else
		ret = A_STACK_REAR;
	return (ret);
}

void	push_run(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	t_run	new_run;
	int		i;

	new_run = ft_deque_run_pop_back(a_stack->runs);
	new_run = (t_run){new_run.len, new_run.ord ^ 1};
	i = -1;
	while (++i < new_run.len)
	{
		pb(a_stack->numbers, b_stack->numbers);
	}
	ft_deque_run_push_back(b_stack->runs, new_run);
}

#define NUM_POS_MASK 0b111

void	merge(
	t_ps_stack *a,
	t_ps_stack *b,
	int status,
	int len
)
{
	int			prime_num_pos;
	const int	num_pos = status & NUM_POS_MASK;

	if (len <= 0)
		return ;
	if (num_pos == AAA || num_pos == AAD || num_pos == ADD || num_pos == DAD)
		prime_num_pos = ps_min_num_pos(a->numbers, b->numbers, num_pos);
	else
		prime_num_pos = ps_max_num_pos(a->numbers, b->numbers, num_pos);
	if (prime_num_pos == A_STACK_TOP)
	{
		pb(a->numbers, b->numbers);
		rb(a->numbers, b->numbers);
	}
	else if (prime_num_pos == B_STACK_TOP)
	{
		rb(a->numbers, b->numbers);
	}
	else if (prime_num_pos == A_STACK_REAR)
	{
		rra(a->numbers, b->numbers);
		pb(a->numbers, b->numbers);
		rb(a->numbers, b->numbers);
	}
	merge(a, b, status, len - 1);
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
		ret.len = ft_deque_run_pop_back(a_stack->runs).len
			+ ft_deque_run_pop_back(b_stack->runs).len;
	else if (num_pos_status == AAD || num_pos_status == DDA)
		ret.len = ft_deque_run_pop_back(a_stack->runs).len
			+ ft_deque_run_pop_back(b_stack->runs).len
			+ ft_deque_run_pop_front(a_stack->runs).len;
	else if (num_pos_status == ADA || num_pos_status == DAD)
		ret.len = ft_deque_run_pop_back(b_stack->runs).len
			+ ft_deque_run_pop_front(a_stack->runs).len;
	else
		ret.len = ft_deque_run_pop_back(a_stack->runs).len
			+ ft_deque_run_pop_front(a_stack->runs).len;
	return (ret);
}

void	push_swap(
	t_ps_stack *a_stack,
	t_ps_stack *b_stack
)
{
	int			status;
	t_run		new_run;

	status = ps_status(a_stack->runs, b_stack->runs);
	if (status & EMPTY)
	{
		push_run(a_stack, b_stack);
	}
	else
	{
		new_run = merge_run(a_stack, b_stack, status);
		ft_deque_run_push_back(b_stack->runs, new_run);
		merge(a_stack, b_stack, status, new_run.len);
	}
	push_swap(a_stack, b_stack);
}
