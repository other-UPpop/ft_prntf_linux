/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:54:39 by rohta             #+#    #+#             */
/*   Updated: 2024/05/22 18:34:17 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp_ch;
	char	*src_ch;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp_ch = (char *) dst;
	src_ch = (char *) src;
	if (dst <= src)
	{
		while (n--)
		{
			*tmp_ch++ = *src_ch++;
		}
	}
	else
	{
		tmp_ch += n;
		src_ch += n;
		while (n--)
		{
			*--tmp_ch = *--src_ch;
		}
	}
	return (dst);
}
