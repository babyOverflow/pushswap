#include "parse.h"
#include "push_swap.h"
#include "ps_merge_action_spec.h"
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
		push_back_ft_deque_int(stack->nums, nums->arr[i]);
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
	const enum e_order	l_order = ft_deque_run_peek_back(l_stack->runs).ord;
	const enum e_order	r_order = ft_deque_run_peek_back(r_stack->runs).ord;

	ret = (t_merge_action_spec){0, 0, Ascending, 0, 0, 0, 0};
	if (l_order == Descending && r_order == Ascending)
	{
		psmaspec_set_left_rear_pos_on(&ret, l_stack);
		psmaspec_set_right_top_pos_on(&ret, r_stack);
		ret.target_ord = Ascending;
	}
	else if (l_order == Descending && r_order == Descending)
	{
		psmaspec_set_left_rear_pos_on(&ret, l_stack);
		psmaspec_set_left_top_pos_on(&ret, l_stack);
		ret.target_ord = Ascending;
	}
	else if (l_order == Ascending && r_order == Ascending)
	{
		psmaspec_set_left_top_pos_on(&ret, l_stack);
		psmaspec_set_right_top_pos_on(&ret, r_stack);
		ret.target_ord = Ascending;
	}
	else {

	}
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
	a_nums = ft_deque_int_create(numbers.len);
	b_nums = ft_deque_int_create(numbers.len);

	t_deque_run a_runs = ft_deque_run_create(numbers.len);
	t_deque_run b_runs = ft_deque_run_create(numbers.len);

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
	t_merge_action_spec spec = get_1run_per_stack_merge_action_spec(&b_stack, &a_stack);
	if (spec.candidates_pos != 0)
		merge(&b_stack, &a_stack, &spec);
	else 
	{
		// push(&a_stack, &b_stack);
		// merge(&b_stack, &a_stack, &spec);
	};

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
