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


int	recur(t_ps_stack *stack, t_ps_stack *temp_stack, int run_size)
{
	const int	runs_num = ft_deque_run_len(stack->runs);
	t_run		run;
	int			temp;
	int			i;

	if (run_size < 6)
		return (run_size);
	while (ft_deque_run_len(stack->runs) != 0)
		push_front_ft_deque_run(temp_stack->runs,
			pop_back_ft_deque_run(stack->runs));
	i = 0;
	while (i < runs_num)
	{
		run = pop_front_ft_deque_run(temp_stack->runs);
		temp = run.len / 3;
		push_back_ft_deque_run(stack->runs, (t_run){temp, run.ord});
		push_back_ft_deque_run(temp_stack->runs, run);
		++i;
	}
	while (i < runs_num * 3)
	{
		run = pop_back_ft_deque_run(temp_stack->runs);
		temp = run.len / 3;
		push_back_ft_deque_run(stack->runs, (t_run){temp, run.ord ^ 1});
		push_front_ft_deque_run(temp_stack->runs, run);
		++i;
	}
	while (ft_deque_run_len(temp_stack->runs) != 0)
			pop_back_ft_deque_run(temp_stack->runs);
	return (recur(stack, temp_stack, run_size / 3));
}

void calcualate_runs(t_ps_stack *stack, t_ps_stack *temp_stack)
{
	const int	num_len = ft_deque_int_len(stack->nums);
	int			asigned;
	int			i;
	t_run		run;

	push_back_ft_deque_run(stack->runs, (t_run){num_len, Descending});
	recur(stack, temp_stack, num_len);
	asigned = num_len - stack->runs->deque[0].len * ft_deque_run_len(stack->runs);
	i = -1;
	while (++i < asigned)
	{
		run = pop_front_ft_deque_run(stack->runs);
		run.len += 1;
		push_back_ft_deque_run(stack->runs, run);
	}
	i = -1;
	while (++i < asigned)
	{
		run = pop_back_ft_deque_run(stack->runs);
		push_front_ft_deque_run(stack->runs, run);
	}
}

void	push_by_runs_ord(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	t_run	run;
	t_merge_action_spec	spec;
	
	spec = (t_merge_action_spec){0, R_STACK_TOP, None, 0, 0, 0, 0, 0};
	spec.target_pos = R_STACK_TOP;
	psmaspec_register_left_rear_as_candidates(&spec, NULL);
	psmaspec_register_left_top_as_candidates(&spec, NULL);
	while (ft_deque_run_len(a_stack->runs) != 0)
	{
		run = pop_back_ft_deque_run(a_stack->runs);
		run.ord ^= 1;
		spec.target_ord = run.ord;
		spec.target_len = run.len;
		push(a_stack, b_stack, &spec);
		push_back_ft_deque_run(b_stack->runs, run);
	}
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
	calcualate_runs(&a_stack, &b_stack);
	push_by_runs_ord(&a_stack, &b_stack);

	while (1)
	{
		push_swap(&b_stack, &a_stack);
		if (ft_deque_run_len(a_stack.runs) <= 1)
			break ;
		push_swap(&a_stack, &b_stack);
		if (ft_deque_run_len(b_stack.runs) <= 1)
			break ;
	}
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
