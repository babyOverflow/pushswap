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

t_ord_desc	*nums_to_ord_int_stack(
	t_parsed_num *nums,
	t_deque_typesymbol *stack
)
{
	int				i;
	int				id;
	t_ord_desc		*descs;
	
	descs = (t_ord_desc *)malloc(sizeof(t_ord_desc) * (nums->len / 2 + 1));
	id = 0;
	i = -1;
	while (++i < nums->len - 1)
	{
		enum e_order	o_orign = compare(nums->arr[i], nums->arr[i + 1]);
		++id;
		descs[id].id = id;
		descs[id].size = 1;
		descs[id].ord = o_orign;
		while (i < nums->len)
		{
			enum e_order o_crnt = compare(nums->arr[i], nums->arr[i + 1]);
			ft_deque_typesymbol_push_back(
				stack,
				(_typesymbol){
					nums->arr[i],
					&descs[id]
				});
			descs[id].size++;
			if (o_orign != o_crnt)
				break ;
			i++;
		}
	}
	return (descs);
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
	t_ord_desc	*descs = nums_to_ord_int_stack(&numbers, &a_stack);
	i = -1;
	while (++i < numbers.len)
	{
		t_ord_int	n = ft_deque_typesymbol_pop_front(&a_stack);
		printf("%d %d\n", n.value, n.ord->id);
	}
}