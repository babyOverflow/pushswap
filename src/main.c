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

t_run	*nums_to_ord_int_stack(t_parsed_num *nums, t_deque_typesymbol *stack)
{
	int				i;
	int				id;
	int				prev;
	static t_run	*runs;
	
	if (runs != NULL)
		free(runs);
	
	runs = (t_run *)malloc(sizeof(t_run) * nums->len);
	id = 0;
	i = -1;
	if (nums->arr[0] < nums->arr[1])
		runs[id].ord = Descending;
	while (++i < nums->len)
	{
	}
	return (runs);
}


int	main(int ac, char *av[])
{
	int					i;
	t_parsed_num		numbers;
	t_deque_typesymbol	a_stack;
	t_deque_typesymbol	b_stack;

	if (ac < 1)
		return (0);
	numbers = ps_parse(ac, av);
	a_stack = ft_deque_typesymbol_create(numbers.len + 1);
	b_stack = ft_deque_typesymbol_create(numbers.len + 1);
	i = 0;
	int prev = numbers.arr[i];
	while (i < numbers.len)
	{
		prev = numbers.arr[i];
		ft_deque_typesymbol_push_back(
			&a_stack,
			(_typesymbol){numbers.arr[i++], });
	}
}