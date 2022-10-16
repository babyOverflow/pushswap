#include "push_swap.h"

void	psmaspec_set_left_top_pos_on(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
);

void	psmaspec_set_right_top_pos_on(
	t_merge_action_spec *self,
	t_ps_stack *r_stack
);

void	psmaspec_set_left_rear_pos_on(
	t_merge_action_spec *self,
	t_ps_stack *l_stack
);

int	psmaspec_has_left_top_candidates(
	t_merge_action_spec *self
);

int	psmaspec_has_left_rear_candidates(
	t_merge_action_spec *self
);

int	psmaspec_has_right_top_candidates(
	t_merge_action_spec *self
);

int	psmaspec_has_right_rear_candidates(
	t_merge_action_spec *self
);