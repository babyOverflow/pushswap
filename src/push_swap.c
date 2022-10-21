/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:48:20 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 14:52:30 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	state = get_ps_status(l_stack->runs, r_stack->runs);
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

void	bubble_down(t_ps_stack *stack, int depth, enum e_order ord)
{
	int	top;
	int	under_top;

	if (depth <= 0)
		return ;
	top = pop_back_ft_deque_int(stack->nums);
	under_top = peek_back_ft_deque_int(stack->nums);
	push_back_ft_deque_int(stack->nums, top);
	if ((ord == Ascending && top < under_top)
		|| (ord == Descending && top > under_top))
		return ;
	sx(stack);
	if (depth - 1 <= 0)
		return ;
	rx(stack);
	bubble_down(stack, depth - 1, ord);
	rrx(stack);
}

void	push(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec
)
{
	int							i;
	enum e_ps_prime_num_pos		prime_num_pos;
	const t_merge_action_spec	only_push = {
		L_STACK_TOP, R_STACK_TOP,
		peek_back_ft_deque_run(l_stack->runs).ord ^ 1,
		peek_back_ft_deque_run(l_stack->runs).len, 1, 0, 0, 0
	};

	i = -1;
	if (spec == NULL)
	{
		spec = (t_merge_action_spec *)&only_push;
	}
	while (++i < spec->target_len)
	{
		prime_num_pos = get_prime_num_pos(l_stack, r_stack, spec);
		if (prime_num_pos == L_STACK_REAR)
			rrx(l_stack);
		px(l_stack, r_stack);
		if (spec != &only_push)
			bubble_down(r_stack, i, spec->target_ord);
	}
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
		new_run.len += pop_back_ft_deque_run(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_TOP)
		new_run.len += pop_back_ft_deque_run(r_stack->runs).len;
	if (spec->candidates_pos & L_STACK_REAR)
		new_run.len += pop_front_ft_deque_run(l_stack->runs).len;
	if (spec->candidates_pos & R_STACK_REAR)
		new_run.len += pop_front_ft_deque_run(r_stack->runs).len;
	(void)new_run;
	if (spec->target_pos == R_STACK_REAR)
		push_front_ft_deque_run(r_stack->runs, new_run);
	else if (spec->target_pos == L_STACK_REAR)
		push_front_ft_deque_run(l_stack->runs, new_run);
	else if (spec->target_pos == R_STACK_TOP)
		push_back_ft_deque_run(r_stack->runs, new_run);
	else if (spec->target_pos == L_STACK_TOP)
		push_back_ft_deque_run(l_stack->runs, new_run);
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

void	merge_and_push(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	spec;
	t_run				tmp_run;
	int					i;
	const int			len = ft_deque_run_len(l_stack->runs);

	if (ft_deque_run_len(l_stack->runs) <= 0)
		return ;
	i = 0;
	while (i < len / 3)
	{
		push(l_stack, r_stack, NULL);
		tmp_run = pop_back_ft_deque_run(l_stack->runs);
		tmp_run.ord ^= 1;
		push_back_ft_deque_run(r_stack->runs, tmp_run);
		++i;
	}
	i = 0;
	while (i < len / 3)
	{
		spec = get_normal_phase_merge_action_spec(l_stack, r_stack);
		tmp_run = merge_run(l_stack, r_stack, &spec);
		merge_number(l_stack, r_stack, &spec, tmp_run.len);
		++i;
	}
}
