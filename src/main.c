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
		enum e_order e = prev > numbers.arr[i] ? Descending : Ascending;
		prev = numbers.arr[i];
		ft_deque_typesymbol_push_back(
			&a_stack,
			(_typesymbol){numbers.arr[i++], e});
	}
	while (a_stack.top - a_stack.rear != 0)
	{
		int	checksum = 0;
		checksum = a_stack.deque[a_stack.top].ord << 3;
		checksum += b_stack.deque[b_stack.top].ord << 2;
		checksum += a_stack.deque[a_stack.rear].ord << 1;
		t_ord_int temp = ft_deque_typesymbol_pop_front(&a_stack);
		printf("%d, %d, %o\n", temp.value, temp.ord, checksum);
		ft_deque_typesymbol_push_back(&b_stack, temp);
	}
}
