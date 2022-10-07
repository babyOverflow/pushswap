#include <stdlib.h>

enum e_order {
	Ascending = 0,
	Descending = 1,
	None
};

typedef struct s_ord_desc {
	enum e_order	ord;
	int				size;
	int				id;
}	t_ord_desc;

typedef struct s_ord_int {
	int		value;
	t_ord_desc	*ord;
}	t_ord_int;

typedef t_ord_int _typesymbol;

typedef struct s_deque_typesymbol {
	int			top;
	int			rear;
	int			capa;
	_typesymbol	*deque;
}	t_deque_typesymbol;

t_deque_typesymbol	ft_deque_typesymbol_create(int size);
void		ft_deque_typesymbol_push_back(t_deque_typesymbol *self, _typesymbol x);
void		ft_deque_typesymbol_push_front(t_deque_typesymbol *self, _typesymbol x);
_typesymbol	ft_deque_typesymbol_pop_back(t_deque_typesymbol *self);
_typesymbol	ft_deque_typesymbol_pop_front(t_deque_typesymbol *self);