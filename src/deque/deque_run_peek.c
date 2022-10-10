#include "push_swap.h"

t_run	ft_deque_run_peek_back(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->top - 1];
	if (self->top < 0)
		ret = self->deque[self->capa - 1];
	return (ret);
}

t_run	ft_deque_run_peek_front(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->rear];
	return (ret);
}