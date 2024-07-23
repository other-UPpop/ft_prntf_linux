/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:44:22 by rohta             #+#    #+#             */
/*   Updated: 2024/05/22 18:34:25 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char		*dst;
	unsigned char		cha;

	dst = (unsigned char *)buf;
	cha = (unsigned char)ch;
	while (n--)
	{
		*dst = cha;
		dst++;
	}
	return (buf);
}
