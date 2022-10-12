#include "push_swap.h"

_typesymbol	ft_deque_typesymbol_peek_back(t_deque_typesymbol *self)
{
	_typesymbol	ret;

	if (self->rear == self->top)
	{
		return (0);
	}
	ret = self->deque[self->top - 1];
	if (self->top < 0)
		ret = self->deque[self->capa - 1];
	return (ret);
}

_typesymbol	ft_deque_typesymbol_peek_front(t_deque_typesymbol *self)
{
	_typesymbol	ret;

	if (self->rear == self->top)
	{
		return (0);
	}
	ret = self->deque[self->rear];
	return (ret);
}