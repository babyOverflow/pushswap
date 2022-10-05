#include <stdlib.h>

typedef int _typesymbol ;
enum e_order {
	Ascending,
	Descending
};

typedef struct s_typesymbol_order {
	_typesymbol		value;
	enum e_order	order;
} t_typesymbol_order;

typedef struct s_deque_typesymbol {
	int			top;
	int			rear;
	int			capa;
	_typesymbol	*deque;
} t_deque_typesymbol;

t_deque_typesymbol	ft_deque_typesymbol_create(int size);
void		ft_deque_typesymbol_push_back(t_deque_typesymbol *self, _typesymbol x);
void		ft_deque_typesymbol_push_front(t_deque_typesymbol *self, _typesymbol x);
_typesymbol	ft_deque_typesymbol_pop_back(t_deque_typesymbol *self);
_typesymbol	ft_deque_typesymbol_pop_front(t_deque_typesymbol *self);
