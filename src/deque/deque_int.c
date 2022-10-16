#include <stdlib.h>
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
