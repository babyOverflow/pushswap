#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define AAAA 0b0000
# define AADA 0b0010
# define ADAA 0b0100
# define ADDA 0b0110
# define DAAA 0b1000
# define DADA 0b1010
# define DDAA 0b1100
# define DDDA 0b1110
# define AAAD 0b0001
# define AADD 0b0011
# define ADAD 0b0101
# define ADDD 0b0111
# define DAAD 0b1001
# define DADD 0b1011
# define DDAD 0b1101
# define DDDD 0b1111

# define EMPTY 0b10000

enum e_order {
	Ascending = 0,
	Descending = 1,
	None
};

# define REST_OF_R_REAR_MASK 0b0111
enum e_ps_prime_num_pos {
	L_STACK_TOP = 0b1,
	R_STACK_TOP = 0b10,
	L_STACK_REAR = 0b100,
	R_STACK_REAR = 0b1000
};

typedef struct s_merge_action_spec {
	enum e_ps_prime_num_pos	candidates_pos;
	enum e_ps_prime_num_pos	target_pos;
	enum e_order			target_ord;
	int						l_stack_top_candidate_num;
	int						r_stack_top_candidate_num;
	int						l_stack_rear_candidate_num;
	int						r_stack_rear_candidate_num;
}	t_merge_action_spec;

typedef struct s_deque_int {
	int	top;
	int	rear;
	int	capa;
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
	t_deque_int	*nums;
	t_deque_run	*runs;
	char		*name;
}	t_ps_stack;


t_deque_int	ft_deque_int_create(int size);
void		push_back_ft_deque_int(t_deque_int *self, int x);
void		push_front_ft_deque_int(t_deque_int *self, int x);
int	pop_back_ft_deque_int(t_deque_int *self);
int	pop_front_ft_deque_int(t_deque_int *self);
int	peek_back_ft_deque_int(t_deque_int *self);
int	peek_front_ft_deque_int(t_deque_int *self);
int			ft_deque_int_len(t_deque_int *self);

t_deque_run	ft_deque_run_create(int size);
void		push_back_ft_deque_run(t_deque_run *self, t_run x);
void		push_front_ft_deque_run(t_deque_run *self, t_run x);
t_run		pop_back_ft_deque_run(t_deque_run *self);
t_run		pop_front_ft_deque_run(t_deque_run *self);
t_run		peek_back_ft_deque_run(t_deque_run *self);
t_run		peek_front_ft_deque_run(t_deque_run *self);
int			ft_deque_run_len(t_deque_run *self);

void	ra(t_deque_int *a_stack, t_deque_int *b_stack);
void	rb(t_deque_int *a_stack, t_deque_int *b_stack);
void	pa(t_deque_int *a_stack, t_deque_int *b_stack);
void	pb(t_deque_int *a_stack, t_deque_int *b_stack);
void	rra(t_deque_int *a_stack, t_deque_int *b_stack);
void	rrb(t_deque_int *a_stack, t_deque_int *b_stack);
void	sa(t_deque_int *a_stack, t_deque_int *b_stack);
void	sb(t_deque_int *a_stack, t_deque_int *b_stack);
void	px(t_ps_stack *stack_src, t_ps_stack *stack_dest);
void	rx(t_ps_stack *x_stack);
void	rrx(t_ps_stack *x_stack);

void	push_swap(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack
);

void	merge(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec	*spec
);

void	merge_final(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	int len
);

void	merge_number(
	t_ps_stack *l_stack,
	t_ps_stack *r_stack,
	t_merge_action_spec *spec,
	int len
);

void	push(t_ps_stack *l_stack, t_ps_stack *r_stack);
#endif