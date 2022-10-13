#include "push_swap.h"

int	peek_back_ft_deque_int(t_deque_int *self)
{
	int	ret;

	if (self->rear == self->top)
	{
		return (0);
	}
	ret = self->deque[self->top - 1];
	if (self->top < 0)
		ret = self->deque[self->capa - 1];
	return (ret);
}

int	peek_front_ft_deque_int(t_deque_int *self)
{
	int	ret;

	if (self->rear == self->top)
	{
		return (0);
	}
	ret = self->deque[self->rear];
	return (ret);
}