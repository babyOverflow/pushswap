/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_action_spec_register_pos.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:13:28 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:22:59 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psmaspec_register_left_top_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
)
{
	self->candidates_pos |= L_STACK_TOP;
	self->l_stack_top_candidate_num = 1;
	if (l_stack != NULL)
		self->l_stack_top_candidate_num
			= peek_back_ft_deque_run(l_stack->runs).len;
}

void	psmaspec_register_right_top_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *r_stack
)
{
	self->candidates_pos |= R_STACK_TOP;
	self->r_stack_top_candidate_num = 1;
	if (r_stack != NULL)
		self->r_stack_top_candidate_num
			= peek_back_ft_deque_run(r_stack->runs).len;
}

void	psmaspec_register_left_rear_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
)
{
	self->candidates_pos |= L_STACK_REAR;
	self->l_stack_rear_candidate_num = 1;
	if (l_stack != NULL)
		self->l_stack_rear_candidate_num
			= peek_front_ft_deque_run(l_stack->runs).len;
}

void	psmaspec_register_right_rear_as_candidates(
	t_merge_action_spec *self,
	t_ps_stack *r_stack
)
{
	self->r_stack_rear_candidate_num = 1;
	self->candidates_pos |= R_STACK_REAR;
	if (r_stack != NULL)
		self->r_stack_rear_candidate_num
			= peek_front_ft_deque_run(r_stack->runs).len;
}
