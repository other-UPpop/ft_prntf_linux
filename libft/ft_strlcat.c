/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:06:20 by rohta             #+#    #+#             */
/*   Updated: 2024/05/18 20:03:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		dst_len;
	size_t		i;

	if (!dst && !src)
		return (0);
	src_len = ft_strlen((const char *)(src));
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
	{
		dst_len++;
	}
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
