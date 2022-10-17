#include "push_swap.h"

void	psmaspec_register_left_top_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
)
{
	self->candidates_pos |= L_STACK_TOP;
	self->l_stack_top_candidate_num +=
		ft_deque_run_peek_back(l_stack->runs).len;
}

void	psmaspec_register_right_top_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *r_stack
)
{
	self->candidates_pos |= R_STACK_TOP;
	self->r_stack_top_candidate_num +=
		ft_deque_run_peek_back(r_stack->runs).len;
}

void	psmaspec_register_left_rear_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
)
{
	self->candidates_pos |= L_STACK_REAR;
	self->l_stack_rear_candidate_num +=
		ft_deque_run_peek_front(l_stack->runs).len;
}

void	psmaspec_register_right_rear_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *r_stack
)
{
	self->candidates_pos |= R_STACK_REAR;
	self->r_stack_rear_candidate_num +=
		ft_deque_run_peek_front(r_stack->runs).len;
}

int	psmaspec_has_left_top_candidates( t_merge_action_spec *self)
{
	if (self->candidates_pos & L_STACK_TOP)
		if (self->l_stack_top_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_left_rear_candidates(t_merge_action_spec *self)
{
	if (self->candidates_pos & L_STACK_REAR)
		if (self->l_stack_rear_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_right_top_candidates( t_merge_action_spec *self)
{
	if (self->candidates_pos & R_STACK_TOP)
		if (self->r_stack_top_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_right_rear_candidates(t_merge_action_spec *self)
{
	if (self->candidates_pos & R_STACK_REAR)
		if (self->r_stack_rear_candidate_num > 0)
			return (1);
	return (0);
}