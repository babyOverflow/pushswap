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
		return (EMPTY | AAAA);
	if (ft_deque_run_peek_back(b_run).ord == None)
		return (EMPTY | DDDA);
	status = 0;
	status |= ft_deque_run_peek_back(a_run).ord << 3;
	status |= ft_deque_run_peek_back(b_run).ord << 2;
	status |= ft_deque_run_peek_front(a_run).ord << 1;
	status |= ft_deque_run_peek_front(b_run).ord << 0;
	return (status);
}

#define PS_STACK_STATUS_TOGGLE_MASK 0b111;

t_merge_action_spec get_normal_phase_merge_action_spec(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	ret;
	int			state;
	
	state = get_ps_status(l_stack->runs, r_stack->runs);
	ret = (t_merge_action_spec){
		0, R_STACK_REAR, None, 0, 0, 0, 0
	};
	if (state == AADA || state == AADD)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		// psmaspec_register_left_top_as_candidates(&ret, l_stack);
		psmaspec_register_right_top_as_candidates(&ret, r_stack);
		ret.target_ord = Ascending;
		ret.target_pos = R_STACK_REAR;
	}
	else if (state == DDAD || state == DDAA)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		// psmaspec_register_left_top_as_candidates(&ret, l_stack);
		psmaspec_register_right_top_as_candidates(&ret, r_stack);
		ret.target_ord = Descending;
		ret.target_pos = R_STACK_REAR;
	}
	// else if (state == AAAA || state == AAAD)
	// {
	// 	psmaspec_register_left_top_as_candidates(&ret, l_stack);
	// 	psmaspec_register_right_top_as_candidates(&ret, r_stack);
	// 	ret.target_ord = Ascending;
	// 	ret.target_pos = R_STACK_REAR;
	// }
	// else if (state == DDDA || state == DDDD)
	// {
	// 	psmaspec_register_left_top_as_candidates(&ret, l_stack);
	// 	psmaspec_register_right_top_as_candidates(&ret, r_stack);
	// 	ret.target_ord = Descending;
	// 	ret.target_pos = R_STACK_REAR;
	// }
	else if (state == ADAD)
	{
		psmaspec_register_left_top_as_candidates(&ret, l_stack);
		psmaspec_register_right_rear_as_candidates(&ret, r_stack);
		ret.target_ord = Descending;
		ret.target_pos = R_STACK_TOP;
	}
	else if (state == ADAA)// || state == ADAD)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_right_top_as_candidates(&ret, r_stack);
		ret.target_ord = Descending;
		ret.target_pos = R_STACK_REAR;
	}
	else if (state == DADD || state == DADA)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_right_top_as_candidates(&ret, r_stack);
		ret.target_ord = Ascending;
		ret.target_pos = R_STACK_REAR;
	}
	else if (state == ADDA || state == ADDD)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_left_top_as_candidates(&ret, l_stack);
		ret.target_ord = Descending;
		ret.target_pos = R_STACK_TOP;
	}
	else if (state == DAAD || state == DAAA)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_left_top_as_candidates(&ret, l_stack);
		ret.target_ord = Ascending;
		ret.target_pos = R_STACK_TOP;
	}
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
	t_run		new_run;

	new_run.ord = spec->target_ord;
	new_run.len = 0;
	if (spec->candidates_pos & L_STACK_TOP)
		new_run.len += ft_deque_run_pop_back(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_TOP)
		new_run.len += ft_deque_run_pop_back(r_stack->runs).len;
	if (spec->candidates_pos & L_STACK_REAR)
		new_run.len += ft_deque_run_pop_front(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_REAR)
		new_run.len += ft_deque_run_pop_front(r_stack->runs).len;
	(void)new_run;
	if (spec->target_pos == R_STACK_REAR)
		ft_deque_run_push_front(r_stack->runs, new_run);
	else if (spec->target_pos == L_STACK_REAR)
		ft_deque_run_push_front(l_stack->runs, new_run);
	else if (spec->target_pos == R_STACK_TOP)
		ft_deque_run_push_back(r_stack->runs, new_run);
	else if (spec->target_pos == L_STACK_TOP)
		ft_deque_run_push_back(l_stack->runs, new_run);
	return (new_run);
}

void	merge(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec	*spec
)
{
	t_run	new_run;

	new_run = merge_run(l_stack, r_stack, spec);
	merge_number(l_stack, r_stack, spec, new_run.len);
}

void	push_swap(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	spec;

	if (ft_deque_run_len(l_stack->runs) <=  1)
		return ;
	spec = get_normal_phase_merge_action_spec(l_stack, r_stack);
	if (spec.target_ord == None)
	{
		push(l_stack, r_stack);
	}
	else
	{
		merge(l_stack, r_stack, &spec);
	}
	push_swap(l_stack, r_stack);
}
