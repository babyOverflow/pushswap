#include "parse.h"
#include "push_swap.h"
#include <stdio.h>

#define DDD 0b111 // 7
#define DDA 0b110 // 6
#define DAD 0b101 // 5
#define DAA 0b100 // 4
#define ADD 0b011 // 3
#define ADA 0b010 // 2
#define AAD 0b001 // 1
#define AAA 0b000 // 0

enum e_order	compare(int x, int y)
{
	if (x < y)
		return (Ascending);
	else
		return (Descending);
}

void	nums_to_int_stack(
	const t_parsed_num *nums,
	t_ps_stack *stack
)
{
	int		i;
	t_run	run;
	enum e_order	crnnt;
	enum e_order	next;

	i = nums->len;
	while (--i >= 0)
		push_back_ft_deque_int(stack->numbers, nums->arr[i]);
	i = nums->len;
	while (--i >= 0)
	{
		crnnt = compare(nums->arr[i - 1], nums->arr[i]);
		next = crnnt;
		run	= (t_run){1, crnnt};
		while (crnnt == next && i > 0)
		{
			run.len++;
			--i;
			next = compare(nums->arr[i - 1], nums->arr[i]);
		}
		ft_deque_run_push_back(stack->runs, run);
	}
}
t_merge_action_spec	get_1run_per_stack_merge_action_spec(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
)
{
	t_merge_action_spec	ret;
	int top;
	int rear;

	ret = (t_merge_action_spec){0, Ascending, 0, 0};
	top = peek_back_ft_deque_int(l_stack->numbers);
	rear = peek_front_ft_deque_int(l_stack->numbers);
	if (top < rear)
		ret.pos_candidates |= L_STACK_TOP;
	else
	 	ret.pos_candidates |= L_STACK_REAR;
	top = peek_back_ft_deque_int(l_stack->numbers);
	rear = peek_front_ft_deque_int(r_stack->numbers);
	if (top < rear)
		ret.pos_candidates |= R_STACK_TOP;
	else
	 	ret.pos_candidates |= R_STACK_REAR;
	return (ret);
}

int	main(int ac, char *av[])
{
	int					i;
	t_parsed_num		numbers;
	t_deque_int	a_nums;
	t_deque_int	b_nums;
	int			n; 

	if (ac < 1)
		return (0);
	numbers = ps_parse(ac, av);
	a_nums = ft_deque_int_create(numbers.len + 2);
	b_nums = ft_deque_int_create(numbers.len + 2);

	t_deque_run a_runs = ft_deque_run_create(numbers.len + 1);
	t_deque_run b_runs = ft_deque_run_create(numbers.len + 1);

	t_ps_stack	a_stack = {&a_nums, &a_runs, "a"};
	t_ps_stack	b_stack = {&b_nums, &b_runs, "b"};
	nums_to_int_stack(&numbers, &a_stack);


	while (1)
	{
		push_swap(&a_stack, &b_stack);
		if (ft_deque_run_len(b_stack.runs) <= 1)
			break ;
		push_swap(&b_stack, &a_stack);
		if (ft_deque_run_len(a_stack.runs) <= 1)
			break ;
	}
	// push_swap(&a_stack, &b_stack);
	// push_swap(&b_stack, &a_stack);
	// int	len = ft_deque_int_len(b_stack.numbers) + ft_deque_int_len(a_stack.numbers);
	// get_1run_per_stack_merge_action_spec(&b_stack, &a_stack);
	// merge(&a_stack, &b_stack, &spec);
	n = 1;
	i = -1;
	while (++i < numbers.len && n != 0)
	{
		n = pop_front_ft_deque_int(&b_nums);
		printf("%d \n", n);
	}
	n = 1;
	i = -1;

	while (++i < numbers.len && n != 0)
	{
		n = pop_front_ft_deque_int(&a_nums);
		printf("%d \n", n);
	}
}
