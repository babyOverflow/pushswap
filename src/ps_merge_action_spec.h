/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_action_spec.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:46:41 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/21 16:23:14 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MERGE_ACTION_SPEC_H
# define PS_MERGE_ACTION_SPEC_H
# include "push_swap.h"

void				psmaspec_register_left_top_as_candidates(
						t_merge_action_spec *self,
						t_ps_stack *l_stack);

void				psmaspec_register_right_top_as_candidates(
						t_merge_action_spec *self,
						t_ps_stack *r_stack);

void				psmaspec_register_left_rear_as_candidates(
						t_merge_action_spec *self,
						t_ps_stack *l_stack);

void				psmaspec_register_right_rear_as_candidates(
						t_merge_action_spec *self,
						t_ps_stack *r_stack);

int					psmaspec_has_left_top_candidates(
						t_merge_action_spec *self);

int					psmaspec_has_left_rear_candidates(
						t_merge_action_spec *self);

int					psmaspec_has_right_top_candidates(
						t_merge_action_spec *self);

int					psmaspec_has_right_rear_candidates(
						t_merge_action_spec *self);

t_merge_action_spec	get_normal_phase_merge_action_spec(
						t_ps_stack *l_stack,
						t_ps_stack *r_stack);
#endif