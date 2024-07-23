/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:32:09 by rohta             #+#    #+#             */
/*   Updated: 2024/05/22 18:34:10 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_ch;
	const char	*src_ch;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ch = (char *)dst;
	src_ch = (const char *)src;
	while (n--)
	{
		*dst_ch++ = *src_ch++;
	}
	return (dst);
}
