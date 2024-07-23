/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:05:33 by rohta             #+#    #+#             */
/*   Updated: 2024/05/21 19:23:03 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*memo;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	memo = *lst;
	while (memo)
	{
		next = memo -> next;
		ft_lstdelone(memo, del);
		memo = next;
	}
	*lst = NULL;
}
