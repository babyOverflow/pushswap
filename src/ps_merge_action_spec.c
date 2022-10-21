/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_action_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:13:04 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:16:29 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_merge_action_spec.h"

int	_get_ps_status(
	t_deque_run *a_run,
	t_deque_run *b_run
)
{
	int	status;

	if (peek_back_ft_deque_run(a_run).ord == None)
		return (EMPTY | AAAA);
	if (peek_back_ft_deque_run(b_run).ord == None)
		return (EMPTY | DDDA);
	status = 0;
	status |= peek_back_ft_deque_run(a_run).ord << 3;
	status |= peek_back_ft_deque_run(b_run).ord << 2;
	status |= peek_front_ft_deque_run(a_run).ord << 1;
	status |= peek_front_ft_deque_run(b_run).ord << 0;
	return (status);
}

t_merge_action_spec	get_normal_phase_merge_action_spec(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	ret;
	int					state;

	state = _get_ps_status(l_stack->runs, r_stack->runs);
	ret = (t_merge_action_spec){
		0, R_STACK_REAR, None, 0, 0, 0, 0, 0
	};
	if (state == DAAA || state == DDAA)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_left_top_as_candidates(&ret, l_stack);
		psmaspec_register_right_rear_as_candidates(&ret, r_stack);
		ret.target_ord = Ascending;
		ret.target_pos = R_STACK_TOP;
	}
	else if (state == ADDD || state == AADD)
	{
		psmaspec_register_left_rear_as_candidates(&ret, l_stack);
		psmaspec_register_left_top_as_candidates(&ret, l_stack);
		psmaspec_register_right_rear_as_candidates(&ret, r_stack);
		ret.target_ord = Descending;
		ret.target_pos = R_STACK_TOP;
	}
	return (ret);
}
