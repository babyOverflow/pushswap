/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:53:35 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:34:56 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "push_swap.h"
#include "ps_merge_action_spec.h"

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
	if (psmaspec_has_left_top_candidates(spec) && l_top < num_min)
		num_min = l_top;
	if (psmaspec_has_right_top_candidates(spec) && r_top < num_min)
		num_min = r_top;
	if (psmaspec_has_left_rear_candidates(spec) && l_rear < num_min)
		num_min = l_rear;
	if (psmaspec_has_right_rear_candidates(spec))
		if (peek_front_ft_deque_int(r_stack) < num_min)
			return (R_STACK_REAR);
	if (num_min == l_top && psmaspec_has_left_top_candidates(spec))
		ret = L_STACK_TOP;
	else if (num_min == r_top && psmaspec_has_right_rear_candidates(spec))
		ret = R_STACK_TOP;
	else
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
	if (psmaspec_has_left_top_candidates(spec) && l_top > num_max)
		num_max = l_top;
	if (psmaspec_has_right_top_candidates(spec) && r_top > num_max)
		num_max = r_top;
	if (psmaspec_has_left_rear_candidates(spec) && l_rear > num_max)
		num_max = l_rear;
	if (psmaspec_has_right_rear_candidates(spec))
		if (peek_front_ft_deque_int(r_stack) > num_max)
			return (R_STACK_REAR);
	if (num_max == l_top && psmaspec_has_left_top_candidates(spec))
		ret = L_STACK_TOP;
	else if (num_max == r_top && psmaspec_has_right_top_candidates(spec))
		ret = R_STACK_TOP;
	else
		ret = L_STACK_REAR;
	return (ret);
}

enum e_ps_prime_num_pos	get_prime_num_pos(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	int			prime_num_pos;

	if (spec->target_pos == L_STACK_REAR || spec->target_pos == R_STACK_REAR)
	{
		if (spec->target_ord == Ascending)
			prime_num_pos = ps_min_num_pos(l_stack->nums, r_stack->nums, spec);
		else
			prime_num_pos = ps_max_num_pos(l_stack->nums, r_stack->nums, spec);
	}
	else
	{
		if (spec->target_ord == Ascending)
			prime_num_pos = ps_max_num_pos(l_stack->nums, r_stack->nums, spec);
		else
			prime_num_pos = ps_min_num_pos(l_stack->nums, r_stack->nums, spec);
	}
	return (prime_num_pos);
}

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
