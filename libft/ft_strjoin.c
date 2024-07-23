/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:57:49 by rohta             #+#    #+#             */
/*   Updated: 2024/05/14 18:37:06 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	str_len1;
	size_t	str_len2;
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str_len1 = ft_strlen((char *)(s1));
	str_len2 = ft_strlen((char *)(s2));
	p = (char *)malloc(str_len1 + str_len2 + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s1, str_len1);
	ft_memmove(p + str_len1, s2, str_len2 + 1);
	return (p);
}
