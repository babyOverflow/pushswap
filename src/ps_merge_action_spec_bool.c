/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_action_spec_bool.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:14:47 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:14:54 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	psmaspec_has_left_top_candidates( t_merge_action_spec *self)
{
	if (self->candidates_pos & L_STACK_TOP)
		if (self->l_stack_top_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_left_rear_candidates(t_merge_action_spec *self)
{
	if (self->candidates_pos & L_STACK_REAR)
		if (self->l_stack_rear_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_right_top_candidates( t_merge_action_spec *self)
{
	if (self->candidates_pos & R_STACK_TOP)
		if (self->r_stack_top_candidate_num > 0)
			return (1);
	return (0);
}

int	psmaspec_has_right_rear_candidates(t_merge_action_spec *self)
{
	if (self->candidates_pos & R_STACK_REAR)
		if (self->r_stack_rear_candidate_num > 0)
			return (1);
	return (0);
}
