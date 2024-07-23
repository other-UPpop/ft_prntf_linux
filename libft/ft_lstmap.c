/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:46:28 by rohta             #+#    #+#             */
/*   Updated: 2024/05/25 19:18:27 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	list = ft_lstnew((*f)(lst -> content));
	if (!list)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst -> next;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst -> content));
		if (!temp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, temp);
		lst = lst -> next;
	}
	return (list);
}
