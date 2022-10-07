#include "push_swap.h"

int	ps_status(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	int	status;

	status = 0;
	status |= a_stack->deque[a_stack->top].ord->ord << 2;
	status |= b_stack->deque[b_stack->top].ord->ord << 1;
	status |= a_stack->deque[a_stack->rear].ord->ord << 0;
	return (status);
}

void	push_swap(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	int	status;

	status = ps_status(a_stack, b_stack, descs);
}