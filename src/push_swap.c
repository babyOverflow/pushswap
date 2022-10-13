#include <assert.h>
#include <limits.h>

#include "push_swap.h"
#include "libft.h"

t_merge_action_spec get_nomal_phase_merge_action_spec(
	int status
)
{
	t_merge_action_spec	ret;

	ret.pos_candidates = 0;
	if (status == AAA || status == AAD || status == ADD || status == DAD)
		ret.target_ord = Ascending;
	else
	{
		ret.target_ord = Descending;
		status ^= 0b111;
	}
	if (status == AAA || status == AAD || status == ADD)
		ret.pos_candidates |= L_STACK_TOP;
	if (status == AAA || status == AAD || status == DAD)
		ret.pos_candidates |= R_STACK_TOP;
	if (status == ADD || status == DAD)
		ret.pos_candidates |= L_STACK_REAR;
	return (ret);
}

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
	t_deque_int *l_stack,
	t_deque_int *r_stack,
	t_merge_action_spec *spec
)
{
	enum e_ps_prime_num_pos	ret;
	const int				l_top = peek_back_ft_deque_int(l_stack);
	const int				r_top = peek_back_ft_deque_int(r_stack);
	const int				l_rear = peek_front_ft_deque_int(l_stack);
	int						num_min;

	num_min = INT_MAX;
	if (spec->pos_candidates & L_STACK_TOP && l_top < num_min)
		num_min = l_top;
	if (spec->pos_candidates & R_STACK_TOP && r_top < num_min)
		num_min = r_top;
	if (spec->pos_candidates & L_STACK_REAR && l_rear < num_min)
		num_min = l_rear;
	if (spec->pos_candidates & R_STACK_REAR)
		if (peek_front_ft_deque_int(r_stack) < num_min)
			return (R_STACK_REAR);
	ret = L_STACK_TOP;
	if (num_min == r_top)
		ret = R_STACK_TOP;
	else if (num_min == l_rear)
		ret = L_STACK_REAR;
	return (ret);
}

enum e_ps_prime_num_pos	ps_max_num_pos(
	t_deque_int *l_stack,
	t_deque_int *r_stack,
	t_merge_action_spec *spec
)
{
	enum e_ps_prime_num_pos	ret;
	const int				l_top = peek_back_ft_deque_int(l_stack);
	const int				r_top = peek_back_ft_deque_int(r_stack);
	const int				l_rear = peek_front_ft_deque_int(l_stack);
	int						num_max;

	num_max = INT_MIN;
	if (spec->pos_candidates & L_STACK_TOP && l_top > num_max)
		num_max = l_top;
	if (spec->pos_candidates & R_STACK_TOP && r_top > num_max)
		num_max = r_top;
	if (spec->pos_candidates & L_STACK_REAR && l_rear > num_max)
		num_max = l_rear;
	if (spec->pos_candidates & R_STACK_REAR)
		if (peek_front_ft_deque_int(r_stack) > num_max)
			return (R_STACK_REAR);
	if (num_max == l_top)
		ret = L_STACK_TOP;
	else if (num_max == r_top)
		ret = R_STACK_TOP;
	else
		ret = L_STACK_REAR;
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
	t_merge_action_spec *spec,
	int len
)
{
	int			prime_num_pos;

	if (len <= 1)
		return ;
	if (spec->target_ord == Ascending)
		prime_num_pos = ps_min_num_pos(l_stack->numbers, r_stack->numbers, spec);
	else
		prime_num_pos = ps_max_num_pos(l_stack->numbers, r_stack->numbers, spec);
	if (prime_num_pos == L_STACK_TOP)
	{
		px(l_stack, r_stack);
		rx(r_stack);
	}
	else if (prime_num_pos == R_STACK_TOP)
	{
		rx(r_stack);
	}
	else if (prime_num_pos == L_STACK_REAR)
	{
		rrx(l_stack);
		px(l_stack, r_stack);
		rx(r_stack);
	}
	merge_number(l_stack, r_stack, spec, len - 1);
}

t_run	merge_run(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	t_run		ret;

	ret.ord = spec->target_ord;
	ret.len = 0;
	if (spec->pos_candidates & L_STACK_TOP)
		ret.len += ft_deque_run_pop_back(l_stack->runs).len;
	if (spec->pos_candidates & R_STACK_TOP)
		ret.len += ft_deque_run_pop_back(r_stack->runs).len;
	if (spec->pos_candidates & L_STACK_REAR)
		ret.len += ft_deque_run_pop_front(l_stack->runs).len;
	if (spec->pos_candidates & R_STACK_REAR)
		ret.len += ft_deque_run_pop_front(r_stack->runs).len;
	return (ret);
}

void	merge(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec	*spec
)
{
	t_run	new_run;
	new_run = merge_run(l_stack, r_stack, spec);
	ft_deque_run_push_front(r_stack->runs, new_run);
	merge_number(l_stack, r_stack, spec, new_run.len);
}

void	push_swap(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	int			status;
	t_merge_action_spec	spec;

	if (ft_deque_run_len(l_stack->runs) <=  1)
		return ;
	status = get_ps_status(l_stack->runs, r_stack->runs);
	spec = get_nomal_phase_merge_action_spec(status);
	if (status & EMPTY)
	{
		push(l_stack, r_stack);
	}
	else
	{
		merge(l_stack, r_stack, &spec);
	}
	push_swap(l_stack, r_stack);
}
