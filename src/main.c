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
	t_deque_typesymbol *stack,
	t_deque_run *a_runs
)
{
	int				i;
	enum e_order	o_orign;
	enum e_order	o_crnt;
	t_run			run;

	i = 0;
	o_orign = compare(nums->arr[i], nums->arr[i + 1]);
	run = (t_run){.len = 0, .ord = o_crnt};
	while (i < nums->len)
	{
		o_crnt = o_orign;
		while (o_orign == o_crnt)
		{
			o_crnt = compare(nums->arr[i], nums->arr[i + 1]);
			ft_deque_typesymbol_push_back(stack, nums->arr[i]);
			++run.len;
			if (++i == nums->len)
				return (ft_deque_run_push_back(a_runs, run));
		}
		ft_deque_run_push_back(a_runs, run);
		ft_deque_typesymbol_push_back(stack, nums->arr[i]);
		++i;
		o_orign = compare(nums->arr[i], nums->arr[i + 1]);
		run = (t_run){.len = 1, .ord = o_orign};
	}
	ft_deque_run_push_back(a_runs, run);
}

void	loop(
	enum e_order orign, 
	t_deque_typesymbol *stack,
	t_parsed_num *nums,
	int i
)
{
	enum e_order	current;

	current = compare(nums->arr[i], nums->arr[i + 1]);
	ft_deque_typesymbol_push_back(stack, nums->arr[i]);
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
	a_stack = ft_deque_typesymbol_create(numbers.len + 1);
	b_stack = ft_deque_typesymbol_create(numbers.len + 1);

	t_deque_run a_runs = ft_deque_run_create(numbers.len + 1);
	t_deque_run b_runs = ft_deque_run_create(numbers.len + 1);

	nums_to_int_stack(&numbers, &a_stack, &a_runs);

	t_run	run = ft_deque_run_peek_back(&a_runs);
	printf("run size: %d\n", run.len);

	i = -1;
	push_swap(&a_stack, &b_stack, &a_runs, &b_runs);
	while (++i < numbers.len)
	{
		n = ft_deque_typesymbol_pop_front(&b_stack);
		printf("%d \n", n);
	}
}
