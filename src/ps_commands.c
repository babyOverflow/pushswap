#include "libft.h"
#include "push_swap.h"

void	rx(t_ps_stack *x_stack)
{
	int	temp = pop_back_ft_deque_int(x_stack->nums);
	push_front_ft_deque_int(x_stack->nums, temp);
	ft_printf("r%s\n", x_stack->name);
}

void	rrx(t_ps_stack *x_stack)
{
	int	temp = pop_front_ft_deque_int(x_stack->nums);
	push_back_ft_deque_int(x_stack->nums, temp);
	ft_printf("rr%s\n", x_stack->name);
}

void	px(t_ps_stack *stack_src, t_ps_stack *stack_dest)
{
	int	temp = pop_back_ft_deque_int(stack_src->nums);
	push_back_ft_deque_int(stack_dest->nums, temp);
	ft_printf("p%s\n", stack_dest->name);
}


void	sx(t_ps_stack *x_stack)
{
	int	temp = pop_back_ft_deque_int(x_stack->nums);
	int	temp2= pop_back_ft_deque_int(x_stack->nums);
	push_back_ft_deque_int(x_stack->nums, temp);
	push_back_ft_deque_int(x_stack->nums, temp2);
	ft_printf("s%s\n", x_stack->name);
}
