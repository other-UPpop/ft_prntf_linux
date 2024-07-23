/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:15:34 by rohta             #+#    #+#             */
/*   Updated: 2024/05/22 16:26:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	while ((*s1 || *s2) && n != 0)
	{
		str1 = (unsigned char)*s1;
		str2 = (unsigned char)*s2;
		if (str1 != str2)
		{
			return ((int)(str1 - str2));
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
