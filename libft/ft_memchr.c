/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:30:31 by rohta             #+#    #+#             */
/*   Updated: 2024/05/14 17:49:56 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str1;
	size_t		i;

	str1 = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*str1 == ((char)c))
			return ((void *)(str1));
		i++;
		str1++;
	}
	return (NULL);
}
