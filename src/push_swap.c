#include <assert.h>
#include <limits.h>
#include <stdarg.h>

#include "push_swap.h"
#include "ps_merge_action_spec.h"
#include "libft.h"


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

#define PS_STACK_STATUS_TOGGLE_MASK 0b111;

t_merge_action_spec get_normal_phase_merge_action_spec(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	ret;
	int			status;
	
	status = get_ps_status(l_stack->runs, r_stack->runs);
	ret = (t_merge_action_spec){
		0, 0, Descending, 0, 0, 0, 0
	};
	if (status == AAA || status == AAD || status == ADD || status == DAD)
		ret.target_ord = Ascending;
	else
		status ^= PS_STACK_STATUS_TOGGLE_MASK;
	if (status == AAA || status == AAD || status == ADD)
		psmaspec_set_left_top_pos_on(&ret, l_stack);
	if (status == AAA || status == AAD || status == DAD)
		psmaspec_set_right_top_pos_on(&ret, r_stack);
	if (status == ADD || status == DAD || status == AAD)
		psmaspec_set_left_rear_pos_on(&ret, l_stack);
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


t_run	merge_run(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	t_run		ret;

	ret.ord = spec->target_ord;
	ret.len = 0;
	if (spec->candidates_pos & L_STACK_TOP)
		ret.len += ft_deque_run_pop_back(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_TOP)
		ret.len += ft_deque_run_pop_back(r_stack->runs).len;
	if (spec->candidates_pos & L_STACK_REAR)
		ret.len += ft_deque_run_pop_front(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_REAR)
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
	spec = get_normal_phase_merge_action_spec(l_stack, r_stack);
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
