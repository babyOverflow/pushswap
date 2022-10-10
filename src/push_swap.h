#include <stdlib.h>

enum e_order {
	Ascending = 0,
	Descending = 1,
	None
};

typedef int _typesymbol;

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

t_deque_run	ft_deque_run_create(int size);
void		ft_deque_run_push_back(t_deque_run *self, t_run x);
void		ft_deque_run_push_front(t_deque_run *self, t_run x);
t_run	ft_deque_run_pop_back(t_deque_run *self);
t_run	ft_deque_run_pop_front(t_deque_run *self);
t_run	ft_deque_run_peek_back(t_deque_run *self);
t_run	ft_deque_run_peek_front(t_deque_run *self);

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
	t_deque_run *a_runs,
	t_deque_run *b_runs
);