#include "parse.h"
#include "push_swap.h"
#include "ps_merge_action_spec.h"
#include <stdio.h>

void	nums_to_int_stack(
	const t_parsed_num *nums,
	t_ps_stack *stack
)
{
	int		i;

	i = nums->len;
	while (--i >= 0)
		push_back_ft_deque_int(stack->nums, nums->arr[i]);
}

enum e_order	determin(len, i, order)
{
	int numerator;

	numerator = len / 3;
	if (numerator < 3)
	{
		if (i == 0)
			return order ^ order;
		else if ( i == 1)
			return order ^ 1;
		else
		 	return order ^ order ^ 1;
	}
	if (numerator > i)
		return determin(numerator, i, order ^ order);
	else if (2 * numerator > i)
		return determin(numerator, i - numerator, order ^ 1);
	else if (3 * numerator > i)
		return determin(len - (2 * numerator), i - numerator * 2, order ^ order ^ 1);
	else
	 	return determin(len - (3 * numerator), i - numerator * 3, order);
}

void	push_ordered(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	int	i;
	int j;
	enum e_order	target_order;
	const int		len = ft_deque_int_len(a_stack->nums);
	t_run			run;

	i = -1;
	while (++i < len)
	{
		target_order = determin(len, i, Ascending);
	}
}

void	recur(t_ps_stack *stack, int run_size)
{
	const int	runs_num = ft_deque_run_len(stack->runs);
	t_run		run;
	int			temp;
	int			i;

	if (run_size < 6)
		return ;
	i = -1;
	while (++i < runs_num)
	{
		run = pop_front_ft_deque_run(stack->runs);
		temp = run.len / 3;
		push_back_ft_deque_run(stack->runs,
			(t_run){ run.len - (2 * temp), run.ord ^ run.ord});
		push_back_ft_deque_run(stack->runs, (t_run){temp, run.ord ^ 1});
		push_back_ft_deque_run(stack->runs, (t_run){temp, run.ord ^ run.ord ^ 1});
	}
	recur(stack, run_size / 3);
}

void calcualate_runs(t_ps_stack *stack)
{
	const int	num_len = ft_deque_int_len(stack->nums);

	push_back_ft_deque_run(stack->runs, (t_run){num_len, Ascending});
	recur(stack, num_len);
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
	a_nums = ft_deque_int_create(numbers.len);
	b_nums = ft_deque_int_create(numbers.len);

	t_deque_run a_runs = ft_deque_run_create(numbers.len);
	t_deque_run b_runs = ft_deque_run_create(numbers.len);

	t_ps_stack	a_stack = {&a_nums, &a_runs, "a"};
	t_ps_stack	b_stack = {&b_nums, &b_runs, "b"};
	nums_to_int_stack(&numbers, &a_stack);
	calcualate_runs(&a_stack);


	// n = 1;
	// i = -1;
	// while (++i < numbers.len && n != 0)
	// {
	// 	n = pop_front_ft_deque_int(&b_nums);
	// 	printf("%d \n", n);
	// }

	// n = 1;
	// i = -1;
	// while (++i < numbers.len && n != 0)
	// {
	// 	n = pop_front_ft_deque_int(&a_nums);
	// 	printf("%d \n", n);
	// }
}
