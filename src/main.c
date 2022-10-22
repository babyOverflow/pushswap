/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:51:13 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/22 16:34:37 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "push_swap.h"
#include "ps_merge_action_spec.h"
#include "libft.h"

int	recur(t_deque_run *runs, t_deque_run *tmp_runs, int run_size)
{
	const int	runs_num = ft_deque_run_len(runs);
	const int	temp = run_size / 3;
	int			i;
	t_run		run;

	if (run_size < 6)
		return (run_size);
	while (ft_deque_run_len(runs) != 0)
		push_front_ft_deque_run(tmp_runs, pop_back_ft_deque_run(runs));
	i = -1;
	while (++i < runs_num * 2)
	{
		run = pop_back_ft_deque_run(tmp_runs);
		push_back_ft_deque_run(runs, (t_run){temp, run.ord ^ 1});
		push_front_ft_deque_run(tmp_runs, run);
	}
	while (i < runs_num * 3)
	{
		run = pop_front_ft_deque_run(tmp_runs);
		push_back_ft_deque_run(runs, (t_run){temp, run.ord});
		push_back_ft_deque_run(tmp_runs, run);
		++i;
	}
	clear_ft_deque_run(tmp_runs);
	return (recur(runs, tmp_runs, run_size / 3));
}

void	calcualate_runs(t_ps_stack *stack, t_ps_stack *temp_stack)
{
	const int	num_len = ft_deque_int_len(stack->nums);
	int			asigned;
	int			i;
	t_run		run;

	push_back_ft_deque_run(stack->runs, (t_run){num_len, Descending});
	recur(stack->runs, temp_stack->runs, num_len);
	asigned = num_len
		- stack->runs->deque[0].len * ft_deque_run_len(stack->runs);
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
	t_merge_action_spec	spec;
	t_run				run;

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

void	push_swap(t_ps_stack *a_stack, t_ps_stack *b_stack)
{
	calcualate_runs(a_stack, b_stack);
	push_by_runs_ord(a_stack, b_stack);
	while (1)
	{
		merge_and_push(b_stack, a_stack);
		if (ft_deque_run_len(a_stack->runs) <= 1)
			break ;
		merge_and_push(a_stack, b_stack);
		if (ft_deque_run_len(b_stack->runs) <= 1)
			break ;
	}
	if (ft_deque_run_len(b_stack->runs) >= 1)
	{
		while (ft_deque_int_len(b_stack->nums) != 0)
		{
			rrx(b_stack);
			px(b_stack, a_stack);
		}
	}
}

int	main(int ac, char *av[])
{
	t_parsed_num	numbers;
	t_deque_int		a_nums;
	t_deque_int		b_nums;
	t_deque_run		a_runs;
	t_deque_run		b_runs;

	if (ac < 2)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	numbers = ps_parse(ac, av);
	a_nums = ft_deque_int_from(numbers.arr, numbers.len);
	b_nums = ft_deque_int_create(numbers.len);
	a_runs = ft_deque_run_create(numbers.len);
	b_runs = ft_deque_run_create(numbers.len);
	if (ft_deque_int_len(&a_nums) > 6)
		push_swap(&(t_ps_stack){&a_nums, &a_runs, "a"},
			&(t_ps_stack){&b_nums, &b_runs, "b"});
	else
		push_swap_short(&a_nums, &b_nums);
	delete_ft_deque_int(&a_nums);
	delete_ft_deque_int(&b_nums);
	delete_ft_deque_run(&a_runs);
	delete_ft_deque_run(&b_runs);
}
