/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:53:35 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/22 13:47:18 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_merge_action_spec.h"

void	handle_pos_left_top(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	if (spec->target_pos == R_STACK_REAR)
	{
		px(l_stack, r_stack);
		rx(r_stack);
	}
	else if (spec->target_pos == R_STACK_TOP)
	{
		px(l_stack, r_stack);
	}
	spec->l_stack_top_candidate_num -= 1;
}

void	handle_pos_right_top(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	if (spec->target_pos == R_STACK_REAR)
		rx(r_stack);
	else if (spec->target_pos == L_STACK_TOP)
		px(r_stack, l_stack);
	spec->r_stack_top_candidate_num -= 1;
}

void	handle_pos_left_rear(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	if (spec->target_pos == R_STACK_REAR)
	{
		rrx(l_stack);
		px(l_stack, r_stack);
		rx(r_stack);
	}
	else if (spec->target_pos == L_STACK_TOP)
	{
		rrx(l_stack);
	}
	else if (spec->target_pos == R_STACK_TOP)
	{
		rrx(l_stack);
		px(l_stack, r_stack);
	}
	spec->l_stack_rear_candidate_num -= 1;
}

void	handle_pos_right_rear(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	(void)l_stack;
	if (spec->target_pos == R_STACK_TOP)
	{
		rrx(r_stack);
	}
	spec->r_stack_rear_candidate_num -= 1;
}

void	merge_number(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec,
	int len
)
{
	enum e_ps_prime_num_pos		prime_num_pos;

	prime_num_pos = get_prime_num_pos(l_stack, r_stack, spec);
	if (len < 1)
		return ;
	if (prime_num_pos == L_STACK_TOP)
		handle_pos_left_top(l_stack, r_stack, spec);
	else if (prime_num_pos == R_STACK_TOP)
		handle_pos_right_top(l_stack, r_stack, spec);
	else if (prime_num_pos == L_STACK_REAR)
		handle_pos_left_rear(l_stack, r_stack, spec);
	else
		handle_pos_right_rear(l_stack, r_stack, spec);
	merge_number(l_stack, r_stack, spec, len - 1);
}
