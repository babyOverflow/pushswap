/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:27:48 by seonghyk          #+#    #+#             */
/*   Updated: 2022/04/01 21:29:00 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*current;

	if (lst == NULL)
		return (0);
	ret = 1;
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		ret++;
	}
	return (ret);
}
