#include "push_swap.h"

#define AAA 0b000
#define AAD 0b001 
#define ADA 0b010 
#define ADD 0b011 
#define DAA 0b100
#define DAD 0b101
#define DDA 0b110
#define DDD 0b111

#define EMPTY 0b1000


enum e_ps_prime_num_pos {
	A_STACK_TOP,
	B_STACK_TOP,
	A_STACK_REAR,
	B_STACK_REAR
};

int	ps_status(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	int	status;

	if (ft_deque_typesymbol_peek_back(a_stack).ord == NULL)
		return (EMPTY | AAA);
	if (ft_deque_typesymbol_peek_back(b_stack).ord == NULL)
		return (EMPTY | DDD);
	status = 0;
	status |= ft_deque_typesymbol_peek_back(a_stack).ord->ord << 2;
	status |= ft_deque_typesymbol_peek_back(b_stack).ord->ord << 1;
	status |= ft_deque_typesymbol_peek_front(a_stack).ord->ord << 0;

	return (status);
}

enum e_ps_prime_num_pos	ps_max_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	const int	a_top = a_stack->deque[a_stack->top - 1].num;
	const int	b_top = b_stack->deque[b_stack->top - 1].num;
	const int	a_rear = a_stack->deque[a_stack->rear].num;
	int			ret;

	if (a_top >= b_top && a_top >= a_rear)
		return (A_STACK_TOP);
	else if (b_top >= a_top && b_top >= a_rear)
		return (B_STACK_TOP);
	else
		return (A_STACK_REAR);
}

enum e_ps_prime_num_pos	ps_min_num_pos(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	const int	a_top = a_stack->deque[a_stack->top].num;
	const int	b_top = b_stack->deque[b_stack->top].num;
	const int	a_rear = a_stack->deque[a_stack->rear].num;
	int			ret;

	if (a_top <= b_top && a_top <= a_rear)
		return (A_STACK_TOP);
	else if (b_top <= a_top && b_top <= a_rear)
		return (B_STACK_TOP);
	else
		return (A_STACK_REAR);
}

void	push_swap(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
)
{
	int	status;
	int	prime_num_pos;

	status = ps_status(a_stack, b_stack, descs);
	if (status == AAA || status == AAD || status == ADD || status == DAA)
		prime_num_pos = ps_max_num_pos(a_stack, b_stack, descs);
	else
		prime_num_pos = ps_min_num_pos(a_stack, b_stack, descs);
	if (prime_num_pos == A_STACK_TOP)
	{
		pa(a_stack, b_stack);
		rb(a_stack, b_stack);
	}
	else if (prime_num_pos == B_STACK_TOP)
	{
		rb(a_stack, b_stack);
	}
	else if (prime_num_pos == A_STACK_REAR)
	{
		rra(a_stack, b_stack);
		pa(a_stack, b_stack);
		rb(a_stack, b_stack);
	}
}