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

int	get_ps_status(
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
	t_deque_int *a_stack,
	t_deque_int *b_stack,
	int status
)
{
	enum e_ps_prime_num_pos	ret;
	const int				a_top = peek_back_ft_deque_int(a_stack);
	const int				b_top = peek_back_ft_deque_int(b_stack);
	const int				a_rear = peek_front_ft_deque_int(a_stack);
	int						num_min;

	num_min = INT_MAX;
	if (status == AAA || status == AAD || status == ADD)
		if (a_top < num_min)
			num_min = a_top;
	if (status == AAA || status == AAD || status == DAD)
		if (b_top < num_min)
			num_min = b_top;
	if (status == ADD || status == DAD)
		if (a_rear < num_min)
			num_min = a_rear;
	if (num_min == a_top)
		ret = A_STACK_TOP;
	else if (num_min == b_top)
		ret = B_STACK_TOP;
	else
		ret = A_STACK_REAR;
	return (ret);
}

enum e_ps_prime_num_pos	ps_max_num_pos(
	t_deque_int *a_stack,
	t_deque_int *b_stack,
	int status
)
{
	enum e_ps_prime_num_pos	ret;
	const int				a_top = peek_back_ft_deque_int(a_stack);
	const int				b_top = peek_back_ft_deque_int(b_stack);
	const int				a_rear = peek_front_ft_deque_int(a_stack);
	int						num_max;

	num_max = INT_MIN;
	if (status == DDD || status == DDA || status == DAA)
		if (a_top > num_max)
			num_max = a_top;
	if (status == DDD || status == DDA || status == ADA)
		if (b_top > num_max)
			num_max = b_top;
	if (status == DAA || status == ADA)
		if (a_rear > num_max)
			num_max = a_rear;
	if (num_max == a_top)
		ret = A_STACK_TOP;
	else if (num_max == b_top)
		ret = B_STACK_TOP;
	else
		ret = A_STACK_REAR;
	return (ret);
}

void	push(t_ps_stack *l_stack, t_ps_stack *r_stack)
{
	t_run	new_run;
	int		i;

	new_run = ft_deque_run_pop_back(l_stack->runs);
	new_run = (t_run){new_run.len, new_run.ord ^ 1};
	i = -1;
	while (++i < new_run.len)
	{
		px(l_stack, r_stack);
	}
	ft_deque_run_push_back(r_stack->runs, new_run);
}

#define NUM_POS_MASK 0b111

void	merge_number(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	int status,
	int len
)
{
	int			prime_num_pos;
	const int	num_pos = status & NUM_POS_MASK;

	if (len <= 1)
		return ;
	if (num_pos == AAA || num_pos == AAD || num_pos == ADD || num_pos == DAD)
		prime_num_pos = ps_min_num_pos(l_stack->numbers, r_stack->numbers, num_pos);
	else
		prime_num_pos = ps_max_num_pos(l_stack->numbers, r_stack->numbers, num_pos);
	if (prime_num_pos == A_STACK_TOP)
	{
		px(l_stack, r_stack);
		rx(r_stack);
	}
	else if (prime_num_pos == B_STACK_TOP)
	{
		rx(r_stack);
	}
	else if (prime_num_pos == A_STACK_REAR)
	{
		rrx(l_stack);
		px(l_stack, r_stack);
		rx(r_stack);
	}
	merge_number(l_stack, r_stack, status, len - 1);
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
			+ ft_deque_run_pop_back(b_stack->runs).len;
	else if (num_pos_status == ADA || num_pos_status == DAD)
		ret.len = ft_deque_run_pop_back(b_stack->runs).len
			+ ft_deque_run_pop_front(a_stack->runs).len;
	else
		ret.len = ft_deque_run_pop_back(a_stack->runs).len
			+ ft_deque_run_pop_front(a_stack->runs).len;
	return (ret);
}

void	merge(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	int	status
)
{
	t_run	new_run;
	new_run = merge_run(l_stack, r_stack, status);
	ft_deque_run_push_front(r_stack->runs, new_run);
	merge_number(l_stack, r_stack, status, new_run.len);
}

void	push_swap(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	int			status;

	if (ft_deque_run_len(l_stack->runs) <=  1)
		return ;
	status = get_ps_status(l_stack->runs, r_stack->runs);
	if (status & EMPTY)
	{
		push(l_stack, r_stack);
	}
	else
	{
		merge(l_stack, r_stack, status);
	}
	push_swap(l_stack, r_stack);
}
