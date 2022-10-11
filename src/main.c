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
	if (x > y)
		return (Ascending);
	else
		return (Descending);
}

void	nums_to_int_stack(
	t_parsed_num *nums,
	t_ps_stack *stack
)
{
	int				i;
	enum e_order	o_crnt;
	t_run			run;

	i = nums->len - 1;
	run = (t_run){.len = 0, .ord = compare(nums->arr[i - 1], nums->arr[i])};
	while (i >= 0)
	{
		o_crnt = run.ord;
		while (run.ord == o_crnt)
		{
			ft_deque_typesymbol_push_back(stack->numbers, nums->arr[i]);
			++run.len;
			if (--i < 0)
				return (ft_deque_run_push_back(stack->runs, run));
			o_crnt = compare(nums->arr[i - 1], nums->arr[i]);
		}
		ft_deque_run_push_back(stack->runs, run);
		ft_deque_typesymbol_push_back(stack->numbers, nums->arr[i]);
		--i;
		run = (t_run){1, compare(nums->arr[i - 1], nums->arr[i])};
	}
	ft_deque_run_push_back(stack->runs, run);
}

int	main(int ac, char *av[])
{
	int					i;
	t_parsed_num		numbers;
	t_deque_typesymbol	a_stack;
	t_deque_typesymbol	b_stack;
	int			n; 

	if (ac < 1)
		return (0);
	numbers = ps_parse(ac, av);
	a_stack = ft_deque_typesymbol_create(numbers.len + 2);
	b_stack = ft_deque_typesymbol_create(numbers.len + 2);

	t_deque_run a_runs = ft_deque_run_create(numbers.len + 1);
	t_deque_run b_runs = ft_deque_run_create(numbers.len + 1);

	nums_to_int_stack(&numbers, &((t_ps_stack){&a_stack, &a_runs}));


	i = -1;
	push_swap(&a_stack, &b_stack, &a_runs, &b_runs);
	push_swap(&a_stack, &b_stack, &a_runs, &b_runs);
	while (++i < numbers.len)
	{
		n = ft_deque_typesymbol_pop_front(&b_stack);
		printf("%d \n", n);
	}
}
