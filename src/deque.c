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
	if (self->top < 0)
	{
		self->top = self->capa;
		ret = self->deque[--self->top];
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
	ret = self->deque[self->rear];
	self->rear++;
	if (self->rear >= self->capa)
	{
		self->rear = 0;
	}
	return (ret);
}

void	ft_deque_typesymbol_push_back(t_deque_typesymbol *self, _typesymbol x)
{
	self->deque[self->top++] = x;
	if (self->top >= self->capa)
		self->top = 0;
}

void	ft_deque_typesymbol_push_front(t_deque_typesymbol *self, _typesymbol x)
{
	if (--self->rear < 0)
		self->rear = self->capa - 1;
	self->deque[self->rear] = x;
}

t_deque_typesymbol	ft_deque_typesymbol_create(int size)
{
	t_deque_typesymbol	self;
	
	self.deque = (_typesymbol *)malloc(sizeof(_typesymbol) * size);
	if (self.deque == NULL)
		exit(-1);
	self.capa = size;
	self.rear = 0;
	self.top = 0;
	return (self);
}
