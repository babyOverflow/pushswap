#include <stdlib.h>
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
