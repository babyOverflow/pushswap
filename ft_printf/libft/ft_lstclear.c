/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:27:23 by seonghyk          #+#    #+#             */
/*   Updated: 2022/04/01 19:38:23 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if ((*lst) == NULL)
	{
		return ;
	}
	temp = (*lst)->next;
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
	ft_lstclear(&temp, del);
}
