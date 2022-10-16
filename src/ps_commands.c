#include "libft.h"
#include "push_swap.h"

void	ra(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)b_stack;
	int	temp = pop_back_ft_deque_int(a_stack);
	push_front_ft_deque_int(a_stack, temp);
	ft_printf("ra\n");
}

void	rb(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)a_stack;
	int	temp = pop_back_ft_deque_int(b_stack);
	push_front_ft_deque_int(b_stack, temp);
	ft_printf("rb\n");
}

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

void	pb(t_deque_int *a_stack, t_deque_int *b_stack)
{
	int	temp = pop_back_ft_deque_int(a_stack);
	push_back_ft_deque_int(b_stack, temp);
	ft_printf("pa\n");
}

void	rra(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)b_stack;
	int	temp = pop_front_ft_deque_int(a_stack);
	push_back_ft_deque_int(a_stack, temp);
	ft_printf("rra\n");
}

void	rrb(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)a_stack;
	int	temp = pop_front_ft_deque_int(b_stack);
	push_back_ft_deque_int(b_stack, temp);
	ft_printf("rrb\n");
}

void	sa(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)b_stack;
	int	temp = pop_back_ft_deque_int(a_stack);
	int	temp2= pop_back_ft_deque_int(a_stack);
	push_back_ft_deque_int(a_stack, temp);
	push_back_ft_deque_int(a_stack, temp2);
	ft_printf("sa\n");
}

void	sb(t_deque_int *a_stack, t_deque_int *b_stack)
{
	(void)a_stack;
	int	temp = pop_back_ft_deque_int(b_stack);
	int	temp2= pop_back_ft_deque_int(b_stack);
	push_back_ft_deque_int(b_stack, temp);
	push_back_ft_deque_int(b_stack, temp2);
	ft_printf("sb\n");
}
