/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:25:12 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/22 19:14:09 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_merge_action_spec.h"
#include "push_swap.h"

void	push_swap_size_2(t_ps_stack *stack)
{
	const int	top = peek_back_ft_deque_int(stack->nums);
	const int	rear = peek_front_ft_deque_int(stack->nums);

	if (top > rear)
		sx(stack);
}

void	push_swap_size_3(t_ps_stack *stack)
{
	const int	top = pop_back_ft_deque_int(stack->nums);
	const int	middle = peek_back_ft_deque_int(stack->nums);
	const int	rear = peek_front_ft_deque_int(stack->nums);

	push_back_ft_deque_int(stack->nums, top);
	if (rear < middle && rear < top)
	{
		if (middle < top)
			sx(stack);
		rrx(stack);
	}
	else if (middle < top && middle < rear)
	{
		if (top > rear)
			rx(stack);
		else
			sx(stack);
	}
	else if (middle > rear)
	{
		rrx(stack);
		sx(stack);
	}
}

void	push_swap_short(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	t_merge_action_spec	spec;

	spec = (t_merge_action_spec){
		L_STACK_TOP | R_STACK_TOP, R_STACK_REAR, Ascending, 0, 1, 3, 0, 0};
	if (ft_deque_int_len(a_stack->nums) == 1)
		return ;
	else if (ft_deque_int_len(a_stack->nums) == 2)
		push_swap_size_2(a_stack);
	else if (ft_deque_int_len(a_stack->nums) == 3)
		push_swap_size_3(a_stack);
	else if (ft_deque_int_len(a_stack->nums) == 4)
	{
		px(a_stack, b_stack);
		push_swap_size_3(a_stack);
		merge_number(b_stack, a_stack, &spec, 4);
	}
	else if (ft_deque_int_len(a_stack->nums) == 5)
	{
		px(a_stack, b_stack);
		px(a_stack, b_stack);
		push_swap_size_3(a_stack);
		push_swap_size_2(b_stack);
		spec.l_stack_top_candidate_num = 2;
		merge_number(b_stack, a_stack, &spec, 5);
	}
}
