/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:25:12 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/22 17:33:32 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_size_2(t_deque_int *nums)
{
	const int top = pop_back_ft_deque_int(nums);
	const int middle = peek_back_ft_deque_int(nums);
	const int rear = peek_front_ft_deque_int(nums);

	push_back_ft_deque_int(nums, top);
	if (ft_deque_int_len(nums) == 2)
}

void	push_swap_size_3(t_deque_int *nums)
{
	const int top = pop_back_ft_deque_int(nums);
	const int middle = peek_back_ft_deque_int(nums);
	const int rear = peek_front_ft_deque_int(nums);

	push_back_ft_deque_int(nums, top);
	if (rear < middle && rear < top)
	{
		if (middle < top)
			;// sx();
		//rrx()
	}
	else if (middle < top && middle < rear)
	{
		if (top > rear)
			;// rx();
		else
			;// sa()
	}
	else
		if (middle > rear)
		{
			;//rrx()
			//sx()
		}

}

void	push_swap_short(t_deque_int *a_nums, t_deque_int *b_nums)
{
	if (ft_deque_int_len(a_nums) == 1)
		return ;
	else if (ft_deque_int_len(b_nums) == 2)
		push_swap_size_2(a_nums);
	else if (ft_deque_int_len(b_nums) == 3)
		push_swap_size_3(a_nums);
	else if (ft_deque_int_len(b_nums) == 3)
	{

	}
}
