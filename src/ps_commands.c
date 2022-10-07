#include "push_swap.h"

void	ra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_front(a_stack, temp);
}

void	rb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_front(b_stack, temp);
}

void	pa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
}

void	pb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
}

void	rra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_front(a_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
}

void	rrb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_front(b_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
}

void	sa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(a_stack);
	_typesymbol	temp2= ft_deque_typesymbol_pop_back(a_stack);
	ft_deque_typesymbol_push_back(a_stack, temp);
	ft_deque_typesymbol_push_back(a_stack, temp2);
}

void	sb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack)
{
	_typesymbol	temp = ft_deque_typesymbol_pop_back(b_stack);
	_typesymbol	temp2= ft_deque_typesymbol_pop_back(b_stack);
	ft_deque_typesymbol_push_back(b_stack, temp);
	ft_deque_typesymbol_push_back(b_stack, temp2);
}
