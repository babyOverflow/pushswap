#include <stdlib.h>

enum e_order {
	Ascending = 0,
	Descending = 1,
	None
};


typedef struct s_deque_int {
	int			top;
	int			rear;
	int			capa;
	int	*deque;
}	t_deque_int;

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

typedef struct s_ps_stack {
	t_deque_int	*numbers;
	t_deque_run			*runs;
	char				*name;
}	t_ps_stack;


t_deque_int	ft_deque_int_create(int size);
void		push_back_ft_deque_int(t_deque_int *self, int x);
void		push_front_ft_deque_int(t_deque_int *self, int x);
int	pop_back_ft_deque_int(t_deque_int *self);
int	pop_front_ft_deque_int(t_deque_int *self);
int	peek_back_ft_deque_int(t_deque_int *self);
int	peek_front_ft_deque_int(t_deque_int *self);

t_deque_run	ft_deque_run_create(int size);
void		ft_deque_run_push_back(t_deque_run *self, t_run x);
void		ft_deque_run_push_front(t_deque_run *self, t_run x);
t_run		ft_deque_run_pop_back(t_deque_run *self);
t_run		ft_deque_run_pop_front(t_deque_run *self);
t_run		ft_deque_run_peek_back(t_deque_run *self);
t_run		ft_deque_run_peek_front(t_deque_run *self);
int			ft_deque_run_len(t_deque_run *self);

void	ra(t_deque_int *a_stack, t_deque_int *b_stack);
void	rb(t_deque_int *a_stack, t_deque_int *b_stack);
void	pa(t_deque_int *a_stack, t_deque_int *b_stack);
void	pb(t_deque_int *a_stack, t_deque_int *b_stack);
void	rra(t_deque_int *a_stack, t_deque_int *b_stack);
void	rrb(t_deque_int *a_stack, t_deque_int *b_stack);
void	sa(t_deque_int *a_stack, t_deque_int *b_stack);
void	sb(t_deque_int *a_stack, t_deque_int *b_stack);
void	px(t_ps_stack *stack_dest, t_ps_stack *stack_src);
void	rx(t_ps_stack *x_stack);
void	rrx(t_ps_stack *x_stack);

void	push_swap(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
);

void	merge(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	int	status
);
