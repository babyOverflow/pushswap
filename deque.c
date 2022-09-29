#include "deque.h"
#include <sys/stdio.h>

_typesymbol	ft_deque_typesymbol_pop_back(t_deque_typesymbol *self)
{
	_typesymbol	ret;

	if (self->rear == self->top)
	{
		exit(-1);
	}
	ret = self->deque[--self->top];
	if (self->top <= 0)
	{
		self->top = self->capa;
	}
	return (ret);
}

_typesymbol	ft_deque_typesymbol_pop_front(t_deque_typesymbol *self)
{
	_typesymbol	ret;

	if (self->rear == self->top)
	{
		exit(-1);
	}
	ret = self->deque[self->rear++];
	if (self->rear <= self->capa)
	{
		self->rear = 0;
	}
	return (ret);
}

void	ft_deque_typesymbol_push_back(t_deque_typesymbol *self, _typesymbol x)
{
	self->deque[self->top++] = x;
	if (self->top == self->capa)
		self->top = 0;
}

void	ft_deque_typesymbol_push_front(t_deque_typesymbol *self, _typesymbol x)
{
}

t_deque_typesymbol	*ft_deque_typesymbol_create(int size)
{
	t_deque_typesymbol	*self;
	
	self = (t_deque_typesymbol *) malloc(sizeof(t_deque_typesymbol));
	self->deque = (_typesymbol *)malloc(sizeof(_typesymbol) * size);
	self->capa = size;
	self->rear = 0;
	self->top = 0;
	return (self);
}
