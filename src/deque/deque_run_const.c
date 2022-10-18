#include "push_swap.h"

t_run	peek_back_ft_deque_run(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->top - 1];
	if (self->top <= 0)
		ret = self->deque[self->capa - 1];
	return (ret);
}

t_run	peek_front_ft_deque_run(t_deque_run *self)
{
	t_run	ret;

	if (self->rear == self->top)
	{
		return ((t_run){0, None});
	}
	ret = self->deque[self->rear];
	return (ret);
}

int	ft_deque_run_len(t_deque_run *self)
{
	int	ret;

	ret = self->top - self->rear;
	if (ret < 0)
		ret += self->capa;
	return (ret);
}
