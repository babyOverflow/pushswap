/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:48:20 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/22 16:23:38 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>

#include "push_swap.h"
#include "ps_merge_action_spec.h"
#include "libft.h"

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

void	push_swap(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	calcualate_runs(a_stack, b_stack);
	push_by_runs_ord(a_stack, b_stack);
	while (1)
	{
		merge_and_push(b_stack, a_stack);
		if (ft_deque_run_len(a_stack->runs) <= 1)
			break ;
		merge_and_push(a_stack, b_stack);
		if (ft_deque_run_len(b_stack->runs) <= 1)
			break ;
	}
	if (ft_deque_run_len(b_stack->runs) >= 1)
	{
		while (ft_deque_int_len(b_stack->nums) != 0)
		{
			rrx(b_stack);
			px(b_stack, a_stack);
		}
	}
}

