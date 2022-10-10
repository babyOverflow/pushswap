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
	int			num;
	t_ord_desc	*ord;
}	t_ord_num;

typedef t_ord_num _typesymbol;

typedef struct s_deque_typesymbol {
	int			top;
	int			rear;
	int			capa;
	_typesymbol	*deque;
}	t_deque_typesymbol;

typedef struct s_run {
	int				len;
	enum e_order	ord;
}	t_run;

typedef struct s_deque_run {
	int		top;
	int		rear;
	int		capa;
	t_run	*deque;
}	t_deque_run;

t_deque_typesymbol	ft_deque_typesymbol_create(int size);
void		ft_deque_typesymbol_push_back(t_deque_typesymbol *self, _typesymbol x);
void		ft_deque_typesymbol_push_front(t_deque_typesymbol *self, _typesymbol x);
_typesymbol	ft_deque_typesymbol_pop_back(t_deque_typesymbol *self);
_typesymbol	ft_deque_typesymbol_pop_front(t_deque_typesymbol *self);
_typesymbol	ft_deque_typesymbol_peek_back(t_deque_typesymbol *self);
_typesymbol	ft_deque_typesymbol_peek_front(t_deque_typesymbol *self);

void	ra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	rb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	pa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	pb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	rra(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	rrb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	sa(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);
void	sb(t_deque_typesymbol *a_stack, t_deque_typesymbol *b_stack);

void	push_swap(
	t_deque_typesymbol *a_stack,
	t_deque_typesymbol *b_stack,
	t_ord_desc *descs
);