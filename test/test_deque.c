#include <assert.h>
#include <stdio.h>
#include "../src/deque.h"

int	test_push_back()
{
	int size = 4;
	t_deque_typesymbol d = ft_deque_typesymbol_create(size);

	ft_deque_typesymbol_push_back(&d, 1);
	ft_deque_typesymbol_push_back(&d, 2);
	ft_deque_typesymbol_push_back(&d, 3);
	assert(3 == ft_deque_typesymbol_pop_back(&d));
	assert(2 == ft_deque_typesymbol_pop_back(&d));
	assert(1 == ft_deque_typesymbol_pop_back(&d));
	ft_deque_typesymbol_push_back(&d, 1);
	ft_deque_typesymbol_push_back(&d, 2);
	ft_deque_typesymbol_push_back(&d, 3);
	assert(1 == ft_deque_typesymbol_pop_front(&d));
	assert(2 == ft_deque_typesymbol_pop_front(&d));
	assert(3 == ft_deque_typesymbol_pop_front(&d));
	ft_deque_typesymbol_push_back(&d, 4);
	ft_deque_typesymbol_push_back(&d, 5);
	assert(5 == ft_deque_typesymbol_pop_back(&d));
	assert(4 == ft_deque_typesymbol_pop_back(&d));
	ft_deque_typesymbol_push_back(&d, 4);
	ft_deque_typesymbol_push_back(&d, 5);
	ft_deque_typesymbol_push_back(&d, 6);
	assert(4 == ft_deque_typesymbol_pop_front(&d));
	assert(5 == ft_deque_typesymbol_pop_front(&d));
	assert(6 == ft_deque_typesymbol_pop_back(&d));
	return (0);
}

int	test_push_front()
{
	int size = 4;
	t_deque_typesymbol d = ft_deque_typesymbol_create(size);

	ft_deque_typesymbol_push_front(&d, 1);
	ft_deque_typesymbol_push_front(&d, 2);
	ft_deque_typesymbol_push_front(&d, 3);
	assert(1 == ft_deque_typesymbol_pop_back(&d));
	assert(2 == ft_deque_typesymbol_pop_back(&d));
	assert(3 == ft_deque_typesymbol_pop_back(&d));
	ft_deque_typesymbol_push_front(&d, 1);
	ft_deque_typesymbol_push_front(&d, 2);
	ft_deque_typesymbol_push_front(&d, 3);
	assert(3 == ft_deque_typesymbol_pop_front(&d));
	assert(2 == ft_deque_typesymbol_pop_front(&d));
	assert(1 == ft_deque_typesymbol_pop_front(&d));
	ft_deque_typesymbol_push_front(&d, 4);
	ft_deque_typesymbol_push_front(&d, 5);
	assert(4 == ft_deque_typesymbol_pop_back(&d));
	assert(5 == ft_deque_typesymbol_pop_back(&d));
	ft_deque_typesymbol_push_front(&d, 4);
	ft_deque_typesymbol_push_front(&d, 5);
	ft_deque_typesymbol_push_front(&d, 6);
	assert(6 == ft_deque_typesymbol_pop_front(&d));
	assert(5 == ft_deque_typesymbol_pop_front(&d));
	assert(4 == ft_deque_typesymbol_pop_back(&d));
	return (0);
}

int	test_overflow()
{
	int size = 4;
	t_deque_typesymbol d = ft_deque_typesymbol_create(size);
	ft_deque_typesymbol_push_front(&d, 4);
	ft_deque_typesymbol_push_front(&d, 5);
	ft_deque_typesymbol_push_front(&d, 6);
	ft_deque_typesymbol_push_front(&d, 6);
	ft_deque_typesymbol_push_front(&d, 6);

	return (0);
}

int main()
{
	test_push_back();
	test_push_front();
	test_overflow();
}
