/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_int_mut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:05:49 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:06:11 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_back_ft_deque_int(t_deque_int *self)
{
	int	ret;

	if (self->rear == self->top)
	{
		return (0);
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

int	pop_front_ft_deque_int(t_deque_int *self)
{
	int	ret;

	if (self->rear == self->top)
	{
		return (0);
	}
	ret = self->deque[self->rear];
	self->rear++;
	if (self->rear >= self->capa)
	{
		self->rear = 0;
	}
	return (ret);
}

void	push_back_ft_deque_int(t_deque_int *self, int x)
{
	self->deque[self->top++] = x;
	if (self->top >= self->capa)
		self->top = 0;
}

void	push_front_ft_deque_int(t_deque_int *self, int x)
{
	if (--self->rear < 0)
		self->rear = self->capa - 1;
	self->deque[self->rear] = x;
}
