/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_run_mut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:03:00 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:03:22 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_run	pop_back_ft_deque_run(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->top - 1];
	if (self->top <= 0)
	{
		self->top = self->capa;
		ret = self->deque[self->top - 1];
	}
	--self->top;
	return (ret);
}

void	clear_ft_deque_run(t_deque_run *self)
{
	self->top = 0;
	self->rear = 0;
}

t_run	pop_front_ft_deque_run(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->rear];
	self->rear++;
	if (self->rear >= self->capa)
	{
		self->rear = 0;
	}
	return (ret);
}

void	push_back_ft_deque_run(t_deque_run *self, t_run x)
{
	self->deque[self->top++] = x;
	if (self->top >= self->capa)
		self->top = 0;
}

void	push_front_ft_deque_run(t_deque_run *self, t_run x)
{
	if (--self->rear < 0)
		self->rear = self->capa - 1;
	self->deque[self->rear] = x;
}
