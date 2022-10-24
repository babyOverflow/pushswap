/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:47:29 by seonghyk          #+#    #+#             */
/*   Updated: 2022/04/13 13:22:29 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = ft_lstnew(NULL);
	new = temp;
	while (lst != NULL)
	{
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new = temp->next;
	free(temp);
	return (new);
}
