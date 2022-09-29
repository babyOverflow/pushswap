#include <assert.h>
#include <stdio.h>
#include "../deque.h"

int	test_push_back_when_size0()
{
	int size = 3;
	t_deque_typesymbol	*d = ft_deque_typesymbol_create(size);
	assert(d->rear == 0);
	assert(d->top == 0);
	assert(d->capa == size);

	ft_deque_typesymbol_push_back(d, 1);
	assert(d->deque[0] == 1);
	assert(d->rear == 0);
	assert(d->top == 1);
	ft_deque_typesymbol_push_front(d, 2);
	assert(d->deque[size - 1] == 2);
	assert(d->rear == size - 1);
	free(d);
	return (0);
}

int	test_push_front_when_size0()
{
	int size = 3;
	t_deque_typesymbol	*d = ft_deque_typesymbol_create(size);
	assert(d->rear == 0);
	assert(d->top == 0);
	assert(d->capa == size);

	ft_deque_typesymbol_push_front(d, 1);
	assert(d->deque[0] == 1);
	assert(d->top == 0);
	assert(d->rear == size - 1);
	ft_deque_typesymbol_push_back(d, 2);
	assert(d->deque[1] == 2);
	free(d);
	return (0);
}

int	test_push_back_until_full()
{
	int	size = 4;
	t_deque_typesymbol *d = ft_deque_typesymbol_create(size);
	assert(d->top == 0);
	assert(d->rear == 0);
	return (0);
}

int	test_push_loop()
{
	int size = 4;
	t_deque_typesymbol *d = ft_deque_typesymbol_create(size);
	for (int i = 0; i < size; i++)
		ft_deque_typesymbol_push_back(d, 1);
	for (int i = 0; i < size; i++)
		assert(d->deque[i] == 1);
	int x = ft_deque_typesymbol_pop_front(d);
	assert(x == 1);
	ft_deque_typesymbol_push_back(d, 2);
	return (0);
}

int main()
{
	test_push_loop();
	test_push_back_when_size0();
	test_push_front_when_size0();
	test_push_back_until_full();
}
