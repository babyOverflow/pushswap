/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:38:53 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:06:37 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_deque_int	ft_deque_int_create(int size)
{
	t_deque_int	self;

	self.deque = (int *)malloc(sizeof(int) * (size + 1));
	if (self.deque == NULL)
		exit(-1);
	self.capa = size + 1;
	self.rear = 0;
	self.top = 0;
	return (self);
}

void	delete_ft_deque_int(t_deque_int *self)
{
	free(self->deque);
	self->capa = 0;
	self->top = 0;
	self->rear = 0;
}
