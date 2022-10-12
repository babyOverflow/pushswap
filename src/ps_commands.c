#include "libft.h"
#include "push_swap.h"

void	ra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)b_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_front(a_stack, temp);
	ft_printf("ra\n");
}

void	rb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)a_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_front(b_stack, temp);
	ft_printf("rb\n");
}

void	rx(t_ps_stack *x_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(x_stack->numbers);
	ft_deque_typesymbol_push_front(x_stack->numbers, temp);
	ft_printf("r%s\n", x_stack->name);
}

void	pa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
	ft_printf("pa\n");
}

void	pb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
	ft_printf("pa\n");
}

void	rra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)b_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_front(a_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
	ft_printf("rra\n");
}

void	rrb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)a_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_front(b_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
	ft_printf("rrb\n");
}

void	sa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)b_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	_typesymbol	temp2= ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
	ft_deque_typesymbol_push_back(a_stack, temp2);
	ft_printf("sa\n");
}

void	sb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	(void)a_stack;
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	_typesymbol	temp2= ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
	ft_deque_typesymbol_push_back(b_stack, temp2);
	ft_printf("sb\n");
}
