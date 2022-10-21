/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:19:01 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 15:19:04 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rx(t_ps_stack *x_stack)
{
	const int	temp = pop_back_ft_deque_int(x_stack->nums);

	push_front_ft_deque_int(x_stack->nums, temp);
	ft_printf("r%s\n", x_stack->name);
}

void	rrx(t_ps_stack *x_stack)
{
	const int	temp = pop_front_ft_deque_int(x_stack->nums);

	push_back_ft_deque_int(x_stack->nums, temp);
	ft_printf("rr%s\n", x_stack->name);
}

void	px(t_ps_stack *stack_src, t_ps_stack *stack_dest)
{
	const int	temp = pop_back_ft_deque_int(stack_src->nums);

	push_back_ft_deque_int(stack_dest->nums, temp);
	ft_printf("p%s\n", stack_dest->name);
}

void	sx(t_ps_stack *x_stack)
{
	const int	temp = pop_back_ft_deque_int(x_stack->nums);
	const int	temp2 = pop_back_ft_deque_int(x_stack->nums);

	push_back_ft_deque_int(x_stack->nums, temp);
	push_back_ft_deque_int(x_stack->nums, temp2);
	ft_printf("s%s\n", x_stack->name);
}
