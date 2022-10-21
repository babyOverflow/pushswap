/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:38:43 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:05:19 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_deque_run	ft_deque_run_create(int size)
{
	t_deque_run	self;

	self.deque = (t_run *)malloc(sizeof(t_run) * (size + 1));
	if (self.deque == NULL)
		exit(-1);
	self.capa = size + 1;
	self.rear = 0;
	self.top = 0;
	return (self);
}

void	delete_ft_deque_run(t_deque_run *self)
{
	free(self->deque);
	self->capa = 0;
	self->top = 0;
	self->rear = 0;
}
