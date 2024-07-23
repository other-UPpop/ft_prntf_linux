/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:54:21 by rohta             #+#    #+#             */
/*   Updated: 2024/05/14 16:58:58 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*src && srcsize < dstsize -1)
	{
		*dst++ = *src++;
		srcsize++;
	}
	if (dstsize > 0)
		*dst = '\0';
	while (*src++)
		srcsize++;
	return (srcsize);
}
